#include "pch.h"
#include "mainpanelwidget.h"
#include "programstate.h"
#include "imageinfo.h"

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
        top_layout->addItem(spacer1);
        top_layout->addWidget(open_button);

        connect(open_button, &QPushButton::clicked, this, &MainPanelWidget::load_folder);

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

    main_layout_ = new QVBoxLayout();
    main_layout_->setMargin(0);

    init_main_table();
    tags_widget_ = new TagsWidget();
    auto top_layout = init_top_layout();
    auto splitter = init_table_tagswidget_splitter(tags_widget_);
    init_hotkeys();

    main_layout_->addLayout(top_layout);
    main_layout_->addWidget(splitter);

    this->setLayout(main_layout_);
}

void MainPanelWidget::load_folder() {
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
    std::set<std::string> image_extensions {".png", ".jpg", ".bmp"};
    for (const auto &item: std::filesystem::directory_iterator(path)) {
        try {
            if (std::filesystem::is_regular_file(item)) {
                std::string filename = item.path().filename().string();
                std::string file_extension = item.path().extension().string();
                if (image_extensions.contains(file_extension)) {
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
