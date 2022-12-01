#pragma once
#include "ExpressionEvaluator.h"
#include <vector>
#include <sstream>
#include <fstream>
class Subtractor : public ExpressionEvaluator
{
public:
	//Конструктор принимающий количество операндов
	Subtractor(int size);
	//Метод расчета результата по варианту
	double Calculate();
	//Установка операндов
	double setOperand(double* array, int size);
	//Метод сортировки
	void Shuffle();
	//Метод перестановки местами
	void Shuffle(int i, int j);
	//Метод сохранения лога в файл
	void LogToFile(const std::string filename);
	//Метод вывода лога на экран
	void LogToScreen();
private:
	//Важные переменные класса: массив операндов и переменная результатов расчета
	std::vector<double>operands;
	double result;
};

