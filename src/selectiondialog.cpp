#include "selectiondialog.h"
#include "ui_selectiondialog.h"

SelectionDialog::SelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectionDialog)
{
    ui->setupUi(this);
}

QString SelectionDialog::showDialog(const QStringList &list, const QString &label)
{
    ui->listWidget->clear();
    foreach (QString item, list) {
        ui->listWidget->addItem(item);
    }
    ui->label->setText(label);

    int state = exec();
    if (state == QDialog::Accepted && ui->listWidget->currentItem())
        return ui->listWidget->currentItem()->text();
    else
        return QString();
}

int SelectionDialog::showDialog_Index(const QStringList &list, const QString &label)
{
    ui->listWidget->clear();
    foreach (QString item, list) {
        ui->listWidget->addItem(item);
    }
    ui->label->setText(label);

    int state = exec();
    if (state == QDialog::Accepted && ui->listWidget->currentItem())
        return ui->listWidget->currentRow();
    else
        return -1;
}


SelectionDialog::~SelectionDialog()
{
    delete ui;
}
