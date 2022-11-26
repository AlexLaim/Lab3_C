#pragma once
#include "Auto.h"

class Minibus : public Auto
{
public:
	Minibus(double hundredConsume_);
	double consume(int distance);
   
private:
	double hundredConsume;
};

