#include "pch.h"
#include "imageviewerwidget.h"
#include "programstate.h"

ImageViewer::ImageViewer(QWidget *parent): QWidget(parent) {

}

void ImageViewer::paintEvent(QPaintEvent *event) {
    if (!image_.isNull()) {
        QImage image = image_;

        if (image_.width() > this->width() || image_.height() > this->height()) {
            image = image.scaled(this->width(), this->height(), Qt::KeepAspectRatio);
        }

        QPainter painter(this);
        painter.drawImage(QPoint((this->width() - image.width()) / 2, (this->height() - image.height()) / 2), image);
    } else {
        QWidget::paintEvent(event);
    }
}

void ImageViewer::update_image(QString image_path) {
    QString path = ProgramState::instance().get_open_path() + "/" + image_path;
    image_.load(path);
    this->repaint();
}
