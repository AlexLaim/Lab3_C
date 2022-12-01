#pragma once
class IFuelConsume
{
public:
	IFuelConsume() {};
	//Переопределяемый метод расхода топлива
	virtual double consume(int distance) { return 0; };
};

