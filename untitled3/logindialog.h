#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLineEdit>  // Для использования QLineEdit

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    QString getUsername() const;
    QString getPassword() const;

private slots:
    void on_registerButton_clicked();
    void on_showPasswordCheckBox_stateChanged(int state);

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
