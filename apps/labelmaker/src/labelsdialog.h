#ifndef LABELSDIALOG_H
#define LABELSDIALOG_H

#include <QDialog>

namespace Ui {
class LabelsDialog;
}

class LabelsDialog : public QDialog {
    Q_OBJECT

public:
    explicit LabelsDialog(QWidget *parent = nullptr);
    ~LabelsDialog();

private:
    Ui::LabelsDialog *ui;

public slots:
    void create_labels();
    void import_labels();
    void export_labels();

signals:
    void labels_changed();
};

#endif // LABELSDIALOG_H
