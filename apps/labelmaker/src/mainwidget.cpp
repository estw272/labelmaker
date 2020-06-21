#include "pch.h"
#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "mainpanelwidget.h"
#include "imageviewerwidget.h"
#include "qflowlayout.h"
#include "tag.h"
#include "programstate.h"

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

    auto init_hotkeys = [this](MainPanelWidget* main_panel){
        const auto ksequences = ProgramState::instance().get_hotkeys();
        QFlowLayout* fl = main_panel->get_tags_widget()->get_flow_layout();
        size_t tags_size = fl->num_tags();
        for (int i = 0; i < std::min(ksequences.size(), tags_size); ++i) {
            QShortcut* ks = new QShortcut(ksequences[i], this);
            connect(ks, &QShortcut::activated, dynamic_cast<Tag*>(fl->itemAt(i)->widget()), &Tag::toggle);
        }
    };

    main_layout_ = new QVBoxLayout(this);
    main_layout_->setMargin(0);

    ImageViewer* image_viewer = new ImageViewer();
    MainPanelWidget* main_panel = new MainPanelWidget();
    auto* splitter = init_main_splitter(main_panel, image_viewer);

    this->setLayout(main_layout_);
    this->layout()->addWidget(splitter);

    connect(main_panel, &MainPanelWidget::num_images_loaded, this, &MainWidget::forward_num_images_loaded);
    connect(main_panel, &MainPanelWidget::update_image_path, image_viewer, &ImageViewer::update_image);
    connect(this, &MainWidget::save_state, main_panel, &MainPanelWidget::save_state_to_file);

    init_hotkeys(main_panel);
}

void MainWidget::forward_num_images_loaded(int index_selected, int num_imgs) {
    emit num_images_loaded(index_selected, num_imgs);
}

void MainWidget::forward_save_state() {
    emit save_state();
}
