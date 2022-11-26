#pragma once
#include "Auto.h"

class PassengerCar : public Auto
{
public:
	PassengerCar(double hundredConsume_);
	double consume(int distance);
    
private:
	double hundredConsume;
};

