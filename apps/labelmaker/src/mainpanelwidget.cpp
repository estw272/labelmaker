#include "pch.h"
#include "mainpanelwidget.h"
#include "programstate.h"

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

    auto init_signals = [this](){
    };

    main_layout_ = new QVBoxLayout();
    main_layout_->setMargin(0);

    init_main_table();
    tags_widget_ = new TagsWidget();
    auto top_layout = init_top_layout();
    auto splitter = init_table_tagswidget_splitter(tags_widget_);
    init_signals();

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

    std::vector<QString> filenames_vec;
    std::set<std::wstring> image_extensions {L".png", L".jpg", L".bmp"};
    for (const auto &item: std::filesystem::directory_iterator(path)) {
        try {
            if (std::filesystem::is_regular_file(item)) {
                std::wstring filename = item.path().filename().wstring();
                std::wstring file_extension = item.path().extension().wstring();
                if (image_extensions.contains(file_extension)) {
                    filenames_vec.push_back(QString::fromStdWString(filename));
                }
            }
        } catch (const std::exception& e) {
            //#TODO: log exception
        }
    }

    images_table_model_->update_data(filenames_vec);

    //end
    ProgramState::instance().set_open_path(dir_path_qstr);
}
