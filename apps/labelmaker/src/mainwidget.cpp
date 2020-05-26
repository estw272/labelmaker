#include "pch.h"
#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "mainpanelwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MainWidget) {
    ui->setupUi(this);

    init_elements();
}

MainWidget::~MainWidget() {
    delete ui;
}

void MainWidget::init_elements() {
    main_layout_ = new QVBoxLayout(this);
    main_layout_->setMargin(0);

    QSplitter* splitter = new QSplitter(Qt::Horizontal, this);

    QWidget* main_panel_holder = new QWidget();
    QVBoxLayout* main_panel_layout = new QVBoxLayout();
    main_panel_layout->setMargin(0);

    QWidget* image_viewer_holder = new QWidget();
    QVBoxLayout* image_viewer_layout = new QVBoxLayout();
    image_viewer_layout->setMargin(0);

    images_list_table_ = new QTableView();
    QTableView* test2 = new QTableView();
    MainPanelWidget* mpw = new MainPanelWidget();


//    main_panel_layout->addWidget(images_list_table_);
    image_viewer_layout->addWidget(test2);

    main_panel_holder->setLayout(main_panel_layout);
    image_viewer_holder->setLayout(image_viewer_layout);

    splitter->addWidget(mpw);
    splitter->addWidget(image_viewer_holder);
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 3);

    this->setLayout(main_layout_);
    this->layout()->addWidget(splitter);
}
