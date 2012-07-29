#include "mainwindow.h"
#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QFileDialog>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    settings = ((MainWindow *)parent)->getSettings();

    ui->baseLibEdit->setText(settings->value("path/base", "").toString());
    ui->diffLibEdit->setText(settings->value("path/diff", "").toString());

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_baseBrowseButton_clicked()
{
    QString baseDirectory = QFileDialog::getExistingDirectory(this,
                                                tr("Find Files"), QDir::currentPath());

    ui->baseLibEdit->setText(baseDirectory);

}

void SettingsDialog::on_diffBrowseButton_clicked()
{
    QString diffDirectory = QFileDialog::getExistingDirectory(this,
                                                tr("Find Files"), QDir::currentPath());

    ui->diffLibEdit->setText(diffDirectory);
}

void SettingsDialog::accept() {
    settings->setValue("path/base", ui->baseLibEdit->text());
    settings->setValue("path/diff", ui->diffLibEdit->text());
    QDialog::accept();
}
