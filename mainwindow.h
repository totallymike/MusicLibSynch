#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_actionPreferences_triggered();

public:
    explicit MainWindow(QWidget *parent = 0);
    QSettings* getSettings();
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QSettings *settings;
    void showPreferencesDialog();

};

#endif // MAINWINDOW_H
