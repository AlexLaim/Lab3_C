#pragma once
#include <iostream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <algorithm>
#include "IFuelConsume.h"

class Auto : public IFuelConsume
{
protected:
    //Важные переменные класса
    std::string company, model, number;
    int price, yearOfProd;
    int mileage = 0;
    double consumeAuto = 0;
public:
    //Конструктор без параметров
    Auto();
    //Конструктор с параметрами
    Auto(std::string company_, std::string model_, std::string number_, int price_, int yearOfProd_, unsigned int mileage_);
    virtual ~Auto(){}
    //Установка фирмы
    virtual void setCompany(const std::string& company_);
    //Установка модели
    virtual void setModel(const std::string& model_);
    //Установка номера
    virtual void setNumber(const std::string& number_);
    //Установка цены
    virtual void setPrice(int price_);
    //Установка года выпуска
    virtual void setYearOfProd(int yearOfProd_);
    //Имитация поездок
    virtual int setMileage();
    //Получение значений пробега
    virtual int getMileage(Auto car);
    //Вывод информации об автомобилях
    virtual void printInfo();
    //Сохранение данных в файл
    virtual void serialize(const std::string filename);
    //Вывод данных из файла
    virtual void deserialize(const std::string filename);
    //Получение модели авто
    virtual std::string GetModel();
    //Получение года выпуска
    virtual int GetYearOfProd(Auto car);
    //Получение номера
    virtual std::string GetNumber(Auto car);
    //Расход топлива
    double consume(int distance);
};

