#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
signals:
    void  mySignal(QString& s);

private slots:
    void on_pushButton_clicked();
    void button1Fire();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QPushButton *button1;
    QString some_string;
};
#endif // MAINWINDOW_H
