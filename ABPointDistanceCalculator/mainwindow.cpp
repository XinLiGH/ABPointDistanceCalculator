#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <math.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDoubleValidator *doubleValidator = new QDoubleValidator;
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);

    ui->aXLineEdit->setValidator(doubleValidator);
    ui->aYLineEdit->setValidator(doubleValidator);

    ui->bXLineEdit->setValidator(doubleValidator);
    ui->bYLineEdit->setValidator(doubleValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_computePushButton_clicked()
{
    if((ui->aXLineEdit->text().isEmpty() == false) &&
       (ui->aYLineEdit->text().isEmpty() == false) &&
       (ui->bXLineEdit->text().isEmpty() == false) &&
       (ui->bYLineEdit->text().isEmpty() == false))
    {
        double aX = 0.0;
        double aY = 0.0;

        double bX = 0.0;
        double bY = 0.0;

        double d = 0.0;

        aX = QString(ui->aXLineEdit->text()).toDouble(NULL);
        aY = QString(ui->aYLineEdit->text()).toDouble(NULL);

        bX = QString(ui->bXLineEdit->text()).toDouble(NULL);
        bY = QString(ui->bYLineEdit->text()).toDouble(NULL);

        d = pow(pow(aX - bX, 2.0) + pow(aY - bY, 2.0), 1.0 / 2.0);

        ui->distanceLineEdit->setText(QString::number(d, 'g', 20));
    }
    else
    {
        QMessageBox::warning(this, QString(u8"计算失败"), QString(u8"请检查坐标是否输入正确！"), QString(u8"关闭"));
    }
}

void MainWindow::on_clearPushButton_clicked()
{
    ui->aXLineEdit->clear();
    ui->aYLineEdit->clear();

    ui->bXLineEdit->clear();
    ui->bYLineEdit->clear();

    ui->distanceLineEdit->clear();
}
