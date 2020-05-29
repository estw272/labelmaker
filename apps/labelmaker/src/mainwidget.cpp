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
    auto init_main_splitter = [this](QWidget* main_panel, QWidget* image_viewer){
        QSplitter* splitter = new QSplitter(Qt::Horizontal, this);
        splitter->addWidget(main_panel);
        splitter->addWidget(image_viewer);

        splitter->setStretchFactor(0, 1);
        splitter->setStretchFactor(1, 3);

        return splitter;
    };

    main_layout_ = new QVBoxLayout(this);
    main_layout_->setMargin(0);

    //#TODO: temp image viewer widget
    QWidget* image_viewer_holder = new QWidget();
    QVBoxLayout* image_viewer_layout = new QVBoxLayout();
    image_viewer_layout->setMargin(0);
    QTableView* test2 = new QTableView();
    image_viewer_layout->addWidget(test2);
    image_viewer_holder->setLayout(image_viewer_layout);

    MainPanelWidget* main_panel = new MainPanelWidget();
    auto* splitter = init_main_splitter(main_panel, image_viewer_holder);

    this->setLayout(main_layout_);
    this->layout()->addWidget(splitter);

    connect(main_panel, &MainPanelWidget::num_images_loaded, this, &MainWidget::forward_num_images_loaded);
}

void MainWidget::forward_num_images_loaded(int num_imgs) {
    emit num_images_loaded(num_imgs);
}
