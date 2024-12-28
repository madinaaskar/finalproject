#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QString>
#include <random>
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Подключаем кнопки
    connect(ui->buttonRegister, &QPushButton::clicked, this, &MainWindow::on_buttonRegister_clicked);
    connect(ui->buttonGenerate, &QPushButton::clicked, this, &MainWindow::on_buttonGenerate_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Функция для генерации случайного пароля
QString MainWindow::generatePassword(int length)
{
    const QString possibleChars("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    QString password;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, possibleChars.length() - 1);

    for (int i = 0; i < length; ++i) {
        password.append(possibleChars[distribution(generator)]);
    }

    return password;
}

// Функция для регистрации пользователя
void MainWindow::on_buttonRegister_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    // Проверяем, что введены данные
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите имя пользователя и пароль.");
        return;
    }

    // Добавляем данные в таблицу паролей
    int row = ui->tableWidgetPasswords->rowCount();
    ui->tableWidgetPasswords->insertRow(row);
    ui->tableWidgetPasswords->setItem(row, 0, new QTableWidgetItem(username));
    ui->tableWidgetPasswords->setItem(row, 1, new QTableWidgetItem(password));

    // Очищаем поля ввода
    ui->lineEditUsername->clear();
    ui->lineEditPassword->clear();
}
// Функция для удаления строки из таблицы оценок
void MainWindow::on_buttonDelete_clicked()
{
    int row = ui->tableWidgetGrades->currentRow();
    if (row >= 0) {
        ui->tableWidgetGrades->removeRow(row);
    } else {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите строку для удаления.");
    }
}
// Функция для редактирования строки
void MainWindow::on_buttonEdit_clicked()
{
    int row = ui->tableWidgetGrades->currentRow();
    if (row >= 0) {
        // Открытие диалогового окна для редактирования
        QString subject = ui->tableWidgetGrades->item(row, 0)->text();
        int grade = ui->tableWidgetGrades->item(row, 1)->text().toInt();

        bool ok;
        QString newSubject = QInputDialog::getText(this, "Редактировать предмет", "Введите новый предмет:", QLineEdit::Normal, subject, &ok);
        if (ok && !newSubject.isEmpty()) {
            ui->tableWidgetGrades->item(row, 0)->setText(newSubject);
        }

        int newGrade = QInputDialog::getInt(this, "Редактировать оценку", "Введите новую оценку:", grade, 1, 100, 1, &ok);
        if (ok) {
            ui->tableWidgetGrades->item(row, 1)->setText(QString::number(newGrade));
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите строку для редактирования.");
    }
}

void MainWindow::on_addGradeButton_clicked()
{
    // Получаем введенную оценку
    int grade = ui->lineEditGrade->text().toInt();  // Получаем оценку из lineEditGrade

    // Проверяем, что оценка в пределах допустимого диапазона (1-100)
    if (grade >= 1 && grade <= 100) {
        bool ok;

        // Запрос на ввод названия предмета с помощью QInputDialog
        QString subject = QInputDialog::getText(this, "Введите название предмета",
                                                "Название предмета:", QLineEdit::Normal,
                                                "", &ok);

        // Если пользователь ввел название предмета
        if (ok && !subject.isEmpty()) {
            // Добавляем данные в таблицу
            int row = ui->tableWidgetGrades->rowCount();  // Получаем текущую строку в таблице
            ui->tableWidgetGrades->insertRow(row);  // Добавляем новую строку

            // Заполняем ячейки таблицы
            ui->tableWidgetGrades->setItem(row, 0, new QTableWidgetItem(subject));  // Заполняем столбец "Предмет"
            ui->tableWidgetGrades->setItem(row, 1, new QTableWidgetItem(QString::number(grade)));  // Заполняем столбец "Оценка"

            // Обновляем среднее значение
            updateAverageGrade();

            // Очистка поля ввода оценки
            ui->lineEditGrade->clear();
        } else {
            // Если пользователь не ввел название предмета
            QMessageBox::warning(this, "Ошибка", "Вы не ввели название предмета.");
        }
    } else {
        // Если введена некорректная оценка
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите корректную оценку (от 1 до 100).");
    }
}

void MainWindow::updateAverageGrade()
{
    double total = 0;
    int count = 0;

    // Проходим по всем строкам таблицы и суммируем оценки
    for (int row = 0; row < ui->tableWidgetGrades->rowCount(); ++row) {
        QString gradeText = ui->tableWidgetGrades->item(row, 1)->text();  // Получаем текст из столбца "Оценка"
        bool ok;
        double grade = gradeText.toDouble(&ok);  // Преобразуем строку в число
        if (ok) {
            total += grade;  // Добавляем оценку к общей сумме
            ++count;  // Увеличиваем счетчик
        }
    }

    // Если есть хотя бы одна оценка
    if (count > 0) {
        double average = total / count;  // Вычисляем среднее значение
        ui->labelAverage->setText("Средняя оценка: " + QString::number(average, 'f', 2));  // Обновляем labelAverage
    } else {
        ui->labelAverage->setText("Средняя оценка: 0.00");  // Если нет оценок
    }
}


void MainWindow::on_buttonGenerate_clicked()
{
    int passwordLength = 8;  // Длина пароля (можно сделать переменной)

    // Генерируем новый пароль
    QString newPassword = generatePassword(passwordLength);

    // Устанавливаем сгенерированный пароль в поле ввода
    ui->lineEditPassword->setText(newPassword);
}
