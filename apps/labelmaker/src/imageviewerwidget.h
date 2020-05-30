#pragma once
#ifndef _IMAGEVIEWER_H_892383
#define _IMAGEVIEWER_H_892383

class ImageViewer: public QWidget {
    Q_OBJECT

private:
    QImage image_;

public:
    ImageViewer(QWidget* parent = nullptr);

private:
    virtual void paintEvent(QPaintEvent* event) override;

public slots:
    void update_image(QString image_path);

};

#endif
