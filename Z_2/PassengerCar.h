#pragma once
#include "Auto.h"

class PassengerCar : public Auto
{
public:
	//Коструктор с параметром среднего расхода топлива на 100км
	PassengerCar(double hundredConsume_);
	//Метод расхода топлива
	double consume(int distance);
    
private:
	//Расход топлива на 100км
	double hundredConsume;
};

