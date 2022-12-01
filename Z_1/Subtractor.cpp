#define _CRT_SECURE_NO_WARNINGS

#include "Subtractor.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

double Subtractor::setOperand(double* array, int size) {
	//Установка операндов в массив
	for (int i = 0; i < 4; i++)
	{
		operands[i] = array[i];
	}
	return 0;
}

Subtractor::Subtractor(int size) {
	//Создание массива операндов
	operands.resize(size);
}

void Subtractor::Shuffle() {
	//Сортировка по варианту 6
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

void Subtractor::Shuffle(int i, int j) {
	//Перестановка элементов местами
	double temp = operands[j];
	operands[j] = operands[i];
	operands[i] = temp;
}

void Subtractor::LogToFile(const std::string filename) {
	//Сохранение лога в файл
	std::ofstream log(filename, std::ios_base::app | std::ios_base::out);
	time_t now = time(0);
	tm* ltm = localtime(&now);
	log << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " - Вызван метод Subtractor" << std::endl;
}

void Subtractor::LogToScreen() {
	//Вывод лога на экран
	time_t now = time(0);
	tm* ltm = localtime(&now);
	std::cout << std::endl << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " - Вызван метод Subtractor\n" << std::endl;
}

double Subtractor::Calculate() {
	//Расчет результата по варианту 6
	std::cout << "Subtractor:" << std::endl;
	for (size_t i = 0; i < operands.size(); i++)
	{
		std::cout << operands[i] << ", ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < operands.size(); i++)
	{
		result -= operands[i];
		if (operands[i] < 0 && i != operands.size() - 1) {
			std::cout << "(" << operands[i] << ")" << " minus ";
		}
		else if (operands[i] < 0 && i == operands.size() - 1) {
			std::cout << "(" << operands[i] << ")";
		}
		else if (i != operands.size() - 1) {
			std::cout << operands[i] << " minus ";
		}
		else if (i == operands.size() - 1) {
			std::cout << operands[i];
		}
	}
	std::cout << "\nResult = " << result;
	return 0;
}