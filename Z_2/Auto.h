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
    //������ ���������� ������
    std::string company, model, number;
    int price, yearOfProd;
    int mileage = 0;
    double consumeAuto = 0;
public:
    //����������� ��� ����������
    Auto();
    //����������� � �����������
    Auto(std::string company_, std::string model_, std::string number_, int price_, int yearOfProd_, unsigned int mileage_);
    virtual ~Auto(){}
    //��������� �����
    virtual void setCompany(const std::string& company_);
    //��������� ������
    virtual void setModel(const std::string& model_);
    //��������� ������
    virtual void setNumber(const std::string& number_);
    //��������� ����
    virtual void setPrice(int price_);
    //��������� ���� �������
    virtual void setYearOfProd(int yearOfProd_);
    //�������� �������
    virtual int setMileage();
    //��������� �������� �������
    virtual int getMileage(Auto car);
    //����� ���������� �� �����������
    virtual void printInfo();
    //���������� ������ � ����
    virtual void serialize(const std::string filename);
    //����� ������ �� �����
    virtual void deserialize(const std::string filename);
    //��������� ������ ����
    virtual std::string GetModel();
    //��������� ���� �������
    virtual int GetYearOfProd(Auto car);
    //��������� ������
    virtual std::string GetNumber(Auto car);
    //������ �������
    double consume(int distance);
};

