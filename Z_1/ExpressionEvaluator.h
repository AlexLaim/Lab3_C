#pragma once
#include <vector>
#include <sstream>
#include <sstream>
#include <fstream>
class ExpressionEvaluator
{
public:
	ExpressionEvaluator();
	virtual double Calculate();
	virtual void LogToScreen();
	virtual void LogToFile(const std::string filename);
	virtual void Shuffle();
	virtual void Shuffle(int i, int j);
	virtual double setOperand(double* array, int size);
	virtual double setOperand(int i, double value);
	virtual ~ExpressionEvaluator() {};
};

