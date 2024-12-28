#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonRegister_clicked();
    void on_buttonGenerate_clicked();
    void on_addGradeButton_clicked();
    void on_buttonDelete_clicked();
    void on_buttonEdit_clicked();
    void updateAverageGrade();

private:
    Ui::MainWindow *ui;

    QString generatePassword(int length);
};

#endif
