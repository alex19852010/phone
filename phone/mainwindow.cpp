#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QRegularExpression"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText)
    {
        QRegularExpression exp("^[+]{1}[0-9]{11}$");

        if(exp.match(currentText).hasMatch())
        {
            setOklabel();
        }
        else
        {
            setnotOklabel();
        }

    });
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::setOklabel()
{
  ui->label->setText("OK");
  ui->label->setStyleSheet("QLabel {color : green;}");
}

void MainWindow::setnotOklabel()
{
    ui->label->setText("FAIL");
    ui->label->setStyleSheet("QLabel{color : red;}");
}

