#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

public Q_SLOTS:
    void accept();

private slots:
    void on_baseBrowseButton_clicked();

    void on_diffBrowseButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::SettingsDialog *ui;
    QSettings *settings;
};

#endif // SETTINGSDIALOG_H
