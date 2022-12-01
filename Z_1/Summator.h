#pragma once
#include "ExpressionEvaluator.h"
#include <vector>
class Summator : public ExpressionEvaluator
{
public:
	//Конструктор принимающий количество операндов
	Summator(int size);
	//Метод расчета по варианту
	double Calculate();
	//Установка операндов
	double setOperand(int i, double value);
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

