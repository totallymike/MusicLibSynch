#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize settings.
    settings = new QSettings("totallyMike", "MusicLibDiff");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showPreferencesDialog() {
    SettingsDialog dlg(this);
    dlg.exec();
}

void MainWindow::on_actionPreferences_triggered()
{
   showPreferencesDialog();
}

QSettings* MainWindow::getSettings() {
    return this->settings;
}
