#pragma once
#include "Auto.h"

class PassengerCar : public Auto
{
public:
	//���������� � ���������� �������� ������� ������� �� 100��
	PassengerCar(double hundredConsume_);
	//����� ������� �������
	double consume(int distance);
    
private:
	//������ ������� �� 100��
	double hundredConsume;
};

