#pragma once
#include "Auto.h"

class Minibus : public Auto
{
public:
	//���������� � ���������� �������� ������� ������� �� 100��
	Minibus(double hundredConsume_);
	//����� ������� �������
	double consume(int distance);
private:
	//������ ������� �� 100��
	double hundredConsume;
};

