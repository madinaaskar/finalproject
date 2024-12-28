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
    connect(ui->buttonRegister, &QPushButton::clicked, this, &MainWindow::on_buttonRegister_clicked);
    connect(ui->buttonGenerate, &QPushButton::clicked, this, &MainWindow::on_buttonGenerate_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

void MainWindow::on_buttonRegister_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите имя пользователя и пароль.");
        return;
    }

    int row = ui->tableWidgetPasswords->rowCount();
    ui->tableWidgetPasswords->insertRow(row);
    ui->tableWidgetPasswords->setItem(row, 0, new QTableWidgetItem(username));
    ui->tableWidgetPasswords->setItem(row, 1, new QTableWidgetItem(password));

    ui->lineEditUsername->clear();
    ui->lineEditPassword->clear();
}

void MainWindow::on_buttonDelete_clicked()
{
    int row = ui->tableWidgetGrades->currentRow();
    if (row >= 0) {
        ui->tableWidgetGrades->removeRow(row);
    } else {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите строку для удаления.");
    }
}

void MainWindow::on_buttonEdit_clicked()
{
    int row = ui->tableWidgetGrades->currentRow();
    if (row >= 0) {
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
    int grade = ui->lineEditGrade->text().toInt();

    if (grade >= 1 && grade <= 100) {
        bool ok;
        QString subject = QInputDialog::getText(this, "Введите название предмета",
                                                "Название предмета:", QLineEdit::Normal,
                                                "", &ok);

        if (ok && !subject.isEmpty()) {
            int row = ui->tableWidgetGrades->rowCount();
            ui->tableWidgetGrades->insertRow(row);

            ui->tableWidgetGrades->setItem(row, 0, new QTableWidgetItem(subject));
            ui->tableWidgetGrades->setItem(row, 1, new QTableWidgetItem(QString::number(grade)));

            updateAverageGrade();

            ui->lineEditGrade->clear();
        } else {
            QMessageBox::warning(this, "Ошибка", "Вы не ввели название предмета.");
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите корректную оценку (от 1 до 100).");
    }
}

void MainWindow::updateAverageGrade()
{
    double total = 0;
    int count = 0;

    for (int row = 0; row < ui->tableWidgetGrades->rowCount(); ++row) {
        QString gradeText = ui->tableWidgetGrades->item(row, 1)->text();
        bool ok;
        double grade = gradeText.toDouble(&ok);
        if (ok) {
            total += grade;
            ++count;
        }
    }

    if (count > 0) {
        double average = total / count;
        ui->labelAverage->setText("Средняя оценка: " + QString::number(average, 'f', 2));
    } else {
        ui->labelAverage->setText("Средняя оценка: 0.00");
    }
}

void MainWindow::on_buttonGenerate_clicked()
{
    int passwordLength = 8;

    QString newPassword = generatePassword(passwordLength);

    ui->lineEditPassword->setText(newPassword);
}
