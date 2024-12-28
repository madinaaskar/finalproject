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
    void on_buttonRegister_clicked();   // Обработчик нажатия на кнопку Register
    void on_buttonGenerate_clicked();
    void on_addGradeButton_clicked();    // Обработчик для добавления оценки и предмета
    void on_buttonDelete_clicked();      // Обработчик для удаления строки
    void on_buttonEdit_clicked();
    void updateAverageGrade();     // Обработчик нажатия на кнопку Generate

private:
    Ui::MainWindow *ui;

    QString generatePassword(int length);  // Функция для генерации пароля
};

#endif // MAINWINDOW_H
