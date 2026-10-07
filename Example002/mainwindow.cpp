#include "dataprocessor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button1 = new QPushButton("привет!");
    button1->setBaseSize(200,200);
    ui->verticalLayout->addWidget(button1);
    connect(button1, &QPushButton::clicked,
                this, &MainWindow::button1Fire);

    DataProcessor dp;
    connect(button1, &QPushButton::clicked,
                this, [this, &dp] () {dp.processMessage(some_string);});

    connect(this, &MainWindow::mySignal,
                &dp, &DataProcessor::processMessage);

    QString s1 = "blah";
    emit mySignal(s1);
    std::cout<<s1.toStdString()<<std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete model;
}

void MainWindow::on_pushButton_clicked()
{
    QStringList data;
    data << "Яблоко" << "Банан" << "Апельсин";

    if (model)
        delete model;

    // Создаем модель и передаем ей данные (модель должна жить в памяти, например, быть членом класса)
    model = new QStringListModel(this);
    model->setStringList(data);

    this->ui->listView->setModel(model);
}

void MainWindow::button1Fire()
{
    QStringList data;
    data << "Джем" << "Слон" << "Медвед" << "Жираф";

    if (model)
        delete model;

    // Создаем модель и передаем ей данные (модель должна жить в памяти, например, быть членом класса)
    model = new QStringListModel(this);
    model->setStringList(data);

    this->ui->listView->setModel(model);

    emit
}
