#include "pch.h"
#include "mainpanelwidget.h"

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

    auto init_top_layout = []() -> QHBoxLayout* {
        QHBoxLayout* top_layout = new QHBoxLayout();
        QSpacerItem* spacer1 = new QSpacerItem(25, 0, QSizePolicy::Expanding);
        QPushButton* open_button = new QPushButton("Open");
        top_layout->addItem(spacer1);
        top_layout->addWidget(open_button);

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

    main_layout_ = new QVBoxLayout();
    main_layout_->setMargin(0);

    //#TODO: placeholder for tags widget
    QWidget* placeholder_widget = new QWidget();
    QHBoxLayout* temp_l = new QHBoxLayout();
    temp_l->setMargin(0);
    QTableView* temp_t = new QTableView();
    temp_l->addWidget(temp_t);
    placeholder_widget->setLayout(temp_l);

    init_main_table();
    auto top_layout = init_top_layout();
    auto splitter = init_table_tagswidget_splitter(placeholder_widget);

    main_layout_->addLayout(top_layout);
    main_layout_->addWidget(splitter);

    this->setLayout(main_layout_);
}