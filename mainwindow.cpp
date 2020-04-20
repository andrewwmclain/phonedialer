#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <iostream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        myModel(new MyAddressBookModel(this))
{
    ui->setupUi(this);
    ui->tableView->setModel(myModel);

    phoneNumber = "";

    ui->pushButton_call->setIcon(QIcon(":/images/call icon3.PNG"));
    ui->pushButton_back->setIcon(QIcon(":/images/backspace_icon.PNG"));

    QPixmap backgroundImage(":/images/phone_background.jpg");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, backgroundImage);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_an_Address_Book_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                        tr("Open Address Book"), "",
                        tr("Adress Book (*.csv);;All Files (*)"));

    std::cout << fileName.toStdString() << std::endl;

    myModel->openFile(fileName);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    std::cout << index.row() << ", " << index.column() << std::endl;

    phoneNumber = myModel->getPhoneNumber(index.row());
    ui->phoneNum_lineEdit->setText(phoneNumber);
}

void MainWindow::on_pushButton_1_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('1');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('2');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_3_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('3');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_4_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('4');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_5_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('5');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_6_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('6');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_7_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('7');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_8_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('8');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_9_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('9');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_asterisk_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('*');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_0_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('0');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_hashtag_clicked()
{
    if(phoneNumber.length() == 3 || phoneNumber.length() == 7){
        phoneNumber.append('-');
    }
    phoneNumber.append('#');
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_back_clicked()
{
    if(phoneNumber.length() == 0){
        return;
    }
    phoneNumber.remove(phoneNumber.length() - 1, 1);
    if(phoneNumber.length() == 4 || phoneNumber.length() == 8){
        phoneNumber.remove(phoneNumber.length() - 1, 1);
    }
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}

void MainWindow::on_pushButton_call_clicked()
{
    QMessageBox message;
    message.setText("Calling " + phoneNumber);
    message.exec();
    phoneNumber = "";
    ui->phoneNum_lineEdit->setText(phoneNumber);
    myModel->setFilterString(phoneNumber);
}
