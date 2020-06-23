#ifndef LABELSDIALOG_H
#define LABELSDIALOG_H

#include <QDialog>

namespace Ui {
class LabelsDialog;
}

class LabelsDialog : public QDialog {
    Q_OBJECT

private:
    Ui::LabelsDialog *ui;

public:
    explicit LabelsDialog(QWidget *parent = nullptr);
    ~LabelsDialog();

public slots:
    void create_labels();
    void import_labels();
    void export_labels();

private:
    void init_elements();

signals:
    void labels_changed();
};

#endif // LABELSDIALOG_H
