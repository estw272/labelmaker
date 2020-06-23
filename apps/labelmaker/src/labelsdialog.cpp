#include "pch.h"
#include "labelsdialog.h"
#include "ui_labelsdialog.h"
#include "programstate.h"

LabelsDialog::LabelsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::LabelsDialog) {
    ui->setupUi(this);

    connect(ui->ok_button, &QPushButton::clicked, this, &LabelsDialog::create_labels);
    connect(ui->import_button, &QPushButton::clicked, this, &LabelsDialog::import_labels);
    connect(ui->export_button, &QPushButton::clicked, this, &LabelsDialog::export_labels);
}

LabelsDialog::~LabelsDialog() {
    delete ui;
}

void LabelsDialog::create_labels() {
    QString labels_str = ui->labels_textarea->toPlainText();
    QStringList labels_list = labels_str.split(',');

    std::vector<QString> labels_vec;
    for (const auto& item: labels_list) {
        labels_vec.push_back(item.trimmed());
    }

    ProgramState::instance().write_labels(labels_vec);
    emit labels_changed();
    this->accept();
}

void LabelsDialog::import_labels() {
}

void LabelsDialog::export_labels() {
}
