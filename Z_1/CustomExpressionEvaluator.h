#pragma once
#include "ExpressionEvaluator.h"
#include <vector>
#include <sstream>
#include <fstream>
class CustomExpressionEvaluator : public ExpressionEvaluator
{
public:
	CustomExpressionEvaluator(int size);
	double Calculate();
	double setOperand(double* array, int size);
	void Shuffle();
	void Shuffle(int i, int j);
	void LogToFile(const std::string filename);
	void LogToScreen();
private:
	std::vector<double>operands;
	double result;
};

