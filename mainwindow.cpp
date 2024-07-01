#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
MyStack <int> st(8);
void deleteTwoDigit(MyStack <int> &st){
    MyStack <int> t(8);
    int n=0;
    while(!st.isEmpty())
    {
        int value=st.top();
        st.pop();
        if(value<10 or value>99){
            t.push(value);
            n++;
        }
    }
    MyStack <int> t2(n);
    while(!t.isEmpty())
    {
        t2.push(t.top());
        t.pop();
    }
    st=t2;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_action_triggered()
{

    QFile inputFile("input.txt");
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::about(this,"Error","File could not be opened for reading");
        //throw std::runtime_error("File could not be opened for reading");
    }

    QTextStream in(&inputFile);
    while (!in.atEnd()) {
        int value;
        in >> value;
       // qDebug()<<value<<" ";
        st.push(value);
    }

    inputFile.close();
    QString str=st.toQString();
    //qDebug()<<str;
    ui->textEdit->setText(str);
     ui->widget->setVisible(true);
}
*/

void MainWindow::on_action_2_triggered()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_clicked()
{
    int sum =st.Summa();
    QString s=QString::number(sum);
    s="Сумма = "+s;
    QMessageBox::about(this,"Сумма елементов стека",s);
}


void MainWindow::on_pushButton_2_clicked()
{
    st.removeTwoDigitNumbers();
    //MyStack <int> t=st;

    QString str=st.toQString();
    //qDebug()<<str;
    ui->textEdit->setText(str);
}


void MainWindow::on_pushButton_3_clicked()
{
    /*MyStack <int> t=st;
    int max=t.top();
    t.pop();
    while(!t.isEmpty())
    {
        if(t.top()>max)
            max=t.top();

        t.pop();
    }
    */
    int max=st.FindMax();
    QMessageBox::about(this,"Максимальный элемент стека",QString::number(max));
}





void MainWindow::on_action_3_triggered()
{

    QFile inputFile("input.txt");
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::about(this,"Error","File could not be opened for reading");
        //throw std::runtime_error("File could not be opened for reading");
    }

    QTextStream in(&inputFile);
    while (!in.atEnd()) {
        int value;
        in >> value;
        // qDebug()<<value<<" ";
        st.push(value);
    }

    inputFile.close();
    QString str=st.toQString();
    //qDebug()<<str;
    ui->textEdit->setText(str);
    ui->widget->setVisible(true);
}

