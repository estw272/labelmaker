#include "pch.h"
#include "mainpanelwidget.h"

MainPanelWidget::MainPanelWidget(QWidget *parent) : QWidget(parent) {
   init_elements();
}

MainPanelWidget::~MainPanelWidget() {}

void MainPanelWidget::init_elements() {
    main_layout_ = new QVBoxLayout();
    main_layout_->setMargin(0);

    images_table_ = new QTableView();

    QWidget* placeholder_widget = new QWidget();

    QSplitter* splitter = new QSplitter(Qt::Vertical, this);
    splitter->addWidget(images_table_);
    splitter->addWidget(placeholder_widget);
    splitter->setStretchFactor(0, 3);
    splitter->setStretchFactor(1, 1);

    QHBoxLayout* top_layout = new QHBoxLayout();
    QSpacerItem* spacer1 = new QSpacerItem(25, 0, QSizePolicy::Expanding);
    QPushButton* open_button = new QPushButton("Open");
    top_layout->addItem(spacer1);
    top_layout->addWidget(open_button);

    main_layout_->addLayout(top_layout);
    main_layout_->addWidget(splitter);

    this->setLayout(main_layout_);
}