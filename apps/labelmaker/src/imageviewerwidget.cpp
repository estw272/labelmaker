#include "pch.h"
#include "imageviewerwidget.h"
#include "programstate.h"

ImageViewer::ImageViewer(QWidget *parent): QWidget(parent) {

}

void ImageViewer::paintEvent(QPaintEvent *event) {
//    image_.load("C:\\Users\\Tapac\\Desktop\\Плохие ТТН\\306406.jpg");
    if (!image_.isNull()) {
        QImage image = image_;

        const int image_width = image_.width();
        const int image_height = image_.height();
        const double image_ratio = image_width / image_height;

        const int width = this->width();
        const int height  = this->height();

        if (image_width > width || image_height > height) {
            image = image.scaled(width, height, Qt::KeepAspectRatio);
        }

        QPainter painter(this);
        painter.drawImage(QPoint((width - image.width()) / 2, (height - image.height()) / 2), image);
    } else {
        QWidget::paintEvent(event);
    }
}

void ImageViewer::update_image(QString image_path) {
    QString path = ProgramState::instance().get_open_path() + "/" + image_path;
    image_.load(path);
    this->repaint();
}
