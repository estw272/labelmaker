#include "pch.h"
#include "mainpanelwidget.h"
#include "programstate.h"
#include "utility.h"
#include "labelsdialog.h"

MainPanelWidget::MainPanelWidget(QWidget *parent) : QWidget(parent) {
   init_elements();
}

MainPanelWidget::~MainPanelWidget() {}

void MainPanelWidget::init_elements() {
    auto init_main_table = [this](){
        images_table_ = new QTableView();
        images_table_model_ = new ImageListTableModel();
        images_table_model_proxy_ = new QSortFilterProxyModel();
        images_table_model_proxy_->setSourceModel(images_table_model_);
        images_table_->setModel(images_table_model_proxy_);

        images_table_->verticalHeader()->setVisible(false);
        images_table_->verticalHeader()->setDefaultSectionSize(17);
        images_table_->setSortingEnabled(true);
        images_table_->setSelectionMode(QAbstractItemView::SingleSelection);
        images_table_->setSelectionBehavior(QAbstractItemView::SelectRows);
        images_table_->setFocusPolicy(Qt::NoFocus);
        images_table_->setEditTriggers(QAbstractItemView::NoEditTriggers);

        images_table_->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        connect(images_table_->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &MainPanelWidget::image_selection_changed);
    };

    auto init_top_layout = [this]() -> QHBoxLayout* {
        QHBoxLayout* top_layout = new QHBoxLayout();
        QSpacerItem* spacer1 = new QSpacerItem(25, 0, QSizePolicy::Expanding);
        QPushButton* open_button = new QPushButton("Open");
        QPushButton* export_csv_button = new QPushButton("Export");
        top_layout->addWidget(export_csv_button);
        top_layout->addItem(spacer1);
        top_layout->addWidget(open_button);

        connect(open_button, &QPushButton::clicked, this, &MainPanelWidget::load_folder);
        connect(export_csv_button, &QPushButton::clicked, this, &MainPanelWidget::export_to_csv);

        return top_layout;
    };

    auto init_table_tagswidget_splitter = [this](QWidget* tags_widget) -> QSplitter* {
        QSplitter* splitter = new QSplitter(Qt::Vertical, this);
        splitter->addWidget(images_table_);
        splitter->addWidget(tags_widget);
        
        splitter->setStretchFactor(0, 3);
        splitter->setStretchFactor(1, 1);

        return splitter;
    };

    auto init_hotkeys = [this](){
        QShortcut *next_shortcut = new QShortcut(QKeySequence(Qt::Key_Down), this);
        connect(next_shortcut, &QShortcut::activated, this, &MainPanelWidget::next_image);

        QShortcut *prev_shortcut = new QShortcut(QKeySequence(Qt::Key_Up), this);
        connect(prev_shortcut, &QShortcut::activated, this, &MainPanelWidget::prev_image);
    };

    auto init_tags_widget = [this]() -> TagsWidget* {
        TagsWidget* tags_widget = new TagsWidget();
        connect(tags_widget, &TagsWidget::tag_toggled, this, &MainPanelWidget::toggle_tag);
        connect(this, &MainPanelWidget::load_tags, tags_widget, &TagsWidget::load_tags);
        connect(this, &MainPanelWidget::labels_changed, tags_widget, &TagsWidget::add_tags);
        connect(tags_widget, &TagsWidget::new_labels_set, this, &MainPanelWidget::forward_new_labels_set);

        return tags_widget;
    };

    auto init_set_labels_button = [this]() -> QPushButton* {
        QPushButton* set_labels_button = new QPushButton("Set labels");
        connect(set_labels_button, &QPushButton::clicked, this, &MainPanelWidget::set_new_labels);
        return set_labels_button;
    };

    main_layout_ = new QVBoxLayout();
    main_layout_->setMargin(0);

    init_main_table();
    tags_widget_ = init_tags_widget();
    auto top_layout = init_top_layout();
    auto splitter = init_table_tagswidget_splitter(tags_widget_);
    init_hotkeys();
    QPushButton* set_labels_button = init_set_labels_button();

    main_layout_->addLayout(top_layout);
    main_layout_->addWidget(splitter);
    main_layout_->addWidget(set_labels_button);

    this->setLayout(main_layout_);
}

void MainPanelWidget::load_folder() { //#TODO: refactor to different functions
    QFileDialog dialog(this);
    dialog.setDirectory("C:\\");
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setOption(QFileDialog::ShowDirsOnly);
    dialog.setOption(QFileDialog::ReadOnly);
    QStringList res;
    if (dialog.exec()) {
        res = dialog.selectedFiles();
    }

    if (res.empty()) {
        return;
    }

    QString dir_path_qstr = res.at(0);
    std::wstring path = dir_path_qstr.toStdWString();

    ProgramState::instance().set_open_path(dir_path_qstr);

    std::vector<ImageInfo> filenames_vec;
    std::set<ImageInfo> loaded_tags = load_tags_from_file(path + L"/cache.lm");
    load_labels_from_file(path + L"/labels.lm");

    std::set<std::string> image_extensions {".png", ".jpg", ".bmp", ".jpeg"}; //#TODO: move tags filename and extensions somewhere (like json/settings file)
    for (const auto &item: std::filesystem::directory_iterator(path)) {
        try {
            if (std::filesystem::is_regular_file(item)) {
                std::wstring filename = item.path().filename().wstring();
                std::string file_extension = item.path().extension().string();
                if (!image_extensions.contains(file_extension)) {
                    continue;
                }

                ImageInfo temp_info(filename);
                auto idx = loaded_tags.find(temp_info);
                if (idx != loaded_tags.end()) {
                    filenames_vec.push_back(*idx);
                } else {
                    filenames_vec.emplace_back(filename);
                }
            }
        } catch (const std::exception& e) {
            //#TODO: log exception
        }
    }

    images_table_model_->update_data(filenames_vec);
    emit num_images_loaded(-1, static_cast<int>(images_table_model_->data_ref().size()));
}

void MainPanelWidget::image_selection_changed(const QModelIndex& current, const QModelIndex& previous) {
    if (!current.isValid()) {
        return;
    }

    int row = current.row();
    auto model = images_table_->model();
    emit num_images_loaded(row + 1, static_cast<int>(images_table_model_->data_ref().size()));

    QString image_name = model->data(model->index(current.row(), 0)).toString();
    emit update_image_path(image_name);

    //toggle image tags
    std::wstring image_filename = model->data(model->index(current.row(), 0)).toString().toStdWString();
    ImageInfo& item = images_table_model_->get_data_ref(image_filename);
    emit load_tags(item.tags_);
}

void MainPanelWidget::next_image() {
    QModelIndexList selection = images_table_->selectionModel()->selectedIndexes();
    if (!selection.empty()) {
        QModelIndex index = selection.at(0);

        if (index.row() >= images_table_model_->data_ref().size()) {
            return;
        }

        images_table_->selectRow(index.row() + 1);
    } else {
        images_table_->selectRow(0);
    }
}

void MainPanelWidget::prev_image() {
    QModelIndexList selection = images_table_->selectionModel()->selectedIndexes();
    if (!selection.empty()) {
        QModelIndex index = selection.at(0);
        if (index.row() == 0) {
            return;
        }

        images_table_->selectRow(index.row() - 1);
    } else {
        images_table_->selectRow(0);
    }
}

TagsWidget *MainPanelWidget::get_tags_widget() const {
    return tags_widget_;
}

void MainPanelWidget::toggle_tag(QString name, bool active) {
    QModelIndexList selection = images_table_->selectionModel()->selectedIndexes();

    if (!selection.empty()) {
        QModelIndex index = selection.at(0);
        auto model = images_table_->model();
        std::wstring image_filename = model->data(model->index(index.row(), 0)).toString().toStdWString();
        ImageInfo& item = images_table_model_->get_data_ref(image_filename);

        if (active) {
            item.tags_.insert(name.toStdString());
        } else {
            item.tags_.erase(name.toStdString());
        }
        model->dataChanged(index, index);

        emit load_tags(item.tags_);
    }
}

void MainPanelWidget::save_state_to_file() {
    save_labels_to_file();

    std::vector<ImageInfo> data = images_table_model_->get_data();
    if (data.empty()) {
        return;
    }

    ProtoTagsCache proto;
    std::for_each(data.cbegin(), data.cend(), [&proto](auto album){
        if (!album.tags_.empty()) {
            ProtoImageInfo* pinfo = proto.add_image_info();
            pinfo->set_filename(lm::utility::strings::wstr_to_bytes(album.file_name_));
            for (auto item: album.tags_) {
                ProtoTag* tag = pinfo->add_tags();
                tag->set_tag_name(item);
            }
        }
    });

    std::wstring open_path = ProgramState::instance().get_open_path().toStdWString();
    std::fstream output(open_path + L"/cache.lm", std::ios::out | std::ios::trunc | std::ios::binary);
    proto.SerializeToOstream(&output);
}

std::set<ImageInfo> MainPanelWidget::load_tags_from_file(std::wstring tags_file) {
    std::set<ImageInfo> res;

    if (!std::filesystem::exists(std::filesystem::path(tags_file))) {
        return res;
    }

    ProtoTagsCache proto;
    std::fstream input(tags_file, std::ios::in | std::ios::binary);
    if (!proto.ParseFromIstream(&input)) {
        return res;
        //#TODO: logging
    }

    for (int i = 0; i < proto.image_info_size(); ++i) {
        const ProtoImageInfo& pinfo = proto.image_info(i);
        res.emplace(pinfo);
    }

    return res;
}

void MainPanelWidget::export_to_csv() {
    const std::vector<ImageInfo> data = images_table_model_->get_data();
    if (data.empty()) {
        return;
    }

    std::wstring open_path = ProgramState::instance().get_open_path().toStdWString();
    std::ofstream file;
    file.open(open_path + L"/labels.csv", std::ios::binary);
    file << "filename,";
    auto tags = ProgramState::instance().get_tags();
    for (int i = 0; i < tags.size(); ++i) {
        file << lm::utility::strings::wstr_to_bytes(tags.at(i).toStdWString());
        if (i < tags.size() - 1) {
            file << ",";
        }
    }
    file << "\n";

    std::for_each(data.cbegin(), data.cend(), [&file, &tags](auto item){
        std::wcout << item.file_name_.size() << "\n";
        file << lm::utility::strings::wstr_to_bytes(item.file_name_) << ", ";
        for (int i = 0; i < tags.size(); ++i) {
            if (item.tags_.find(tags.at(i).toStdString()) != item.tags_.end()) {
                file << "1";
            } else {
                file << "0";
            }

            if (i < tags.size() - 1) {
                file << ",";
            }
        }

        file << "\n";
    });

    file.close();

    QMessageBox msg_box;
    msg_box.setText("Exported labels to 'labels.csv'");
    msg_box.addButton(QMessageBox::Ok);
    msg_box.exec();
}

void MainPanelWidget::set_new_labels() {
    LabelsDialog labels_dialog;
    if (labels_dialog.exec() == QDialog::Accepted) {
        emit labels_changed();
    }
}

void MainPanelWidget::forward_new_labels_set() {
    emit new_labels_set();
}

void MainPanelWidget::save_labels_to_file() {
    std::vector<QString> tags = ProgramState::instance().get_tags();
    if (tags.empty()) {
        return;
    }

    ProtoLabels proto;
    std::for_each(tags.cbegin(), tags.cend(), [&proto](auto item){
        ProtoTag* ptag = proto.add_tags();
        ptag->set_tag_name(item.toStdString());
    });

    std::wstring open_path = ProgramState::instance().get_open_path().toStdWString();
    std::fstream output(open_path + L"/labels.lm", std::ios::out | std::ios::trunc | std::ios::binary);
    proto.SerializeToOstream(&output);
}

void MainPanelWidget::load_labels_from_file(std::wstring file_path) {
    if (!std::filesystem::exists(std::filesystem::path(file_path))) {
        return;
    }

    ProtoLabels proto;
    std::fstream input(file_path, std::ios::in | std::ios::binary);
    if (!proto.ParseFromIstream(&input)) {
        return;
        //#TODO: logging
    }

    std::vector<QString> labels_vec;
    for (int i = 0; i < proto.tags_size(); ++i) {
        const ProtoTag& pinfo = proto.tags(i);
        labels_vec.push_back(QString::fromStdString(pinfo.tag_name()));
    }

    if (!labels_vec.empty()) {
        set_labels(labels_vec);
    }
}

void MainPanelWidget::set_labels(std::vector<QString> &labels_vec) {
    ProgramState::instance().write_labels(labels_vec);
    emit labels_changed();
}


