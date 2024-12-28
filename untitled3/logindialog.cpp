#include "logindialog.h"
#include "ui_logindialog.h"  // Подключаем файл сгенерированного UI
#include <QMessageBox>
#include <QLineEdit>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);  // Настроить UI
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

QString LoginDialog::getUsername() const
{
    return ui->usernameLineEdit->text();
}

QString LoginDialog::getPassword() const
{
    return ui->passwordLineEdit->text();
}

void LoginDialog::on_registerButton_clicked() {
    QMessageBox::information(this, "Registration", "Redirecting to registration form...");
}

void LoginDialog::on_showPasswordCheckBox_stateChanged(int state) {
    if (state == Qt::Checked) {
        ui->passwordLineEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    }
}
