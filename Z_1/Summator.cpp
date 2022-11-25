#define _CRT_SECURE_NO_WARNINGS

#include "Summator.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <fstream>
#include <chrono>

Summator::Summator(int size) {
	operands.resize(size);
}

void Summator::LogToFile(const std::string filename) {
	std::ofstream log(filename, std::ios_base::app | std::ios_base::out);
	time_t now = time(0);
	tm* ltm = localtime(&now);
	log << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " - Вызван метод Summator" << std::endl;
}

void Summator::LogToScreen() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	std::cout << "\n" << std::endl << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " - Вызван метод Summator" << std::endl;
}

double Summator::setOperand(int i, double value) {
	operands[i] = value;
	return 0;
}

void Summator::Shuffle() {
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

void Summator::Shuffle(int i, int j) {
	double temp = operands[j];
	operands[j] = operands[i];
	operands[i] = temp;
}

double Summator::Calculate() {
	std::cout << "\n\nSummator:" << std::endl;
	for (size_t i = 0; i < operands.size(); i++)
	{
		std::cout << operands[i] << ", ";	
	}
	std::cout<<std::endl;
	for (size_t i = 0; i < operands.size(); i++)
	{
		result += operands[i];
		if (operands[i]<0 && i!= operands.size()-1) {
			std::cout << "(" <<operands[i] <<")" << " plus ";
		}
		else if (operands[i]<0 && i == operands.size()-1) {
			std::cout << "(" <<operands[i] <<")";
		}
		else if (i != operands.size() - 1) {
			std::cout <<operands[i] << " plus ";
		}
		else if (i == operands.size() - 1) {
			std::cout << operands[i];
		}
	}
	std::cout << "\nResult = " << result;
	return 0;
}