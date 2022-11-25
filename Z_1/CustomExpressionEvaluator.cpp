#define _CRT_SECURE_NO_WARNINGS

#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

CustomExpressionEvaluator::CustomExpressionEvaluator(int size) {
	operands.resize(size);
}

double CustomExpressionEvaluator::setOperand(double* array, int size) {
	for (int i = 0; i < size; i++)
	{
		operands[i] = array[i];
	}
	return 0;
}

void CustomExpressionEvaluator::Shuffle() {
	std::vector<double> temp;
	for (size_t i = 0; i < operands.size(); i++)
	{
		if (operands[i] >= 0) {
			temp.push_back(operands[i]);
		}
	}
	std::sort(temp.begin(), temp.end(), std::greater<>());
	for (size_t i = 0; i < temp.size(); i++)
	{
		for (size_t j = 0; j < operands.size(); j++)
		{
			if (operands[j] >= 0) {
				operands[j] = temp[i];
				i++;
			}
		}
	}
}

void CustomExpressionEvaluator::Shuffle(int i, int j) {
	double temp = operands[j];
	operands[j] = operands[i];
	operands[i] = temp;
}

void CustomExpressionEvaluator::LogToFile(const std::string filename) {
	std::ofstream log(filename, std::ios_base::app | std::ios_base::out);
	time_t now = time(0);
	tm* ltm = localtime(&now);
	log << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " - Вызван метод CustomExpressionEvaluator" << std::endl;
}

void CustomExpressionEvaluator::LogToScreen() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	std::cout << "\n" << std::endl << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " - Вызван метод CustomExpressionEvaluator" << std::endl;
}

double CustomExpressionEvaluator::Calculate() {
	std::cout << "\n\nCustom:" << std::endl;
	for (size_t i = 0; i < operands.size(); i++)
	{
		std::cout << operands[i] << ", ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < operands.size(); i++)
	{
		result += operands[i];
		if (i == 1) {
			result = result / 2;
			std::cout << "(" << operands[0] << " plus " << operands[i] << ")" << "/2 plus ";
		}
		else if (operands[i] < 0 && i != operands.size() - 1) {
			std::cout << "(" << operands[i] << ")" << " plus ";
		}
		else if (operands[i] < 0 && i == operands.size() - 1) {
			std::cout << "(" << operands[i] << ")";
		}
		else if (i != operands.size() - 1 && i !=0) {
			std::cout << operands[i] << " plus ";
		}
		else if (i == operands.size() - 1) {
			std::cout << operands[i];
		}
	}
	std::cout << std::endl;
	printf("Result = (%1.0lf + %1.0lf)/2 + (%1.0lf) + %1.0lf + %1.0lf + %1.0lf = %1.0lf", operands[0], operands[1], operands[2], operands[3], operands[4], operands[5], result);
	return 0;
}