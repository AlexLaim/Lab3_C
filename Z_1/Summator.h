#pragma once
#include "ExpressionEvaluator.h"
#include <vector>
class Summator : public ExpressionEvaluator
{
public:
	Summator(int size);
	double Calculate();
	double setOperand(int i, double value);
	void Shuffle();
	void Shuffle(int i, int j);
	void LogToFile(const std::string filename);
	void LogToScreen();
private:
	std::vector<double>operands;
	double result;
};

