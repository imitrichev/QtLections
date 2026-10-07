#include "dataprocessor.h"
#include <iostream>

DataProcessor::DataProcessor(QObject *parent)
    : QObject{parent}
{

}

void DataProcessor::processMessage(QString& s)
{
    //s="Привет!";
    std::cout<<s.toStdString()<<std::endl;
    s="Привет!";
}
