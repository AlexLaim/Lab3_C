#pragma once
class IFuelConsume
{
public:
	IFuelConsume() {};
	virtual double consume(int distance) { return 0; };
};

