#pragma once
#include <vector>
#include <sstream>
#include <sstream>
#include <fstream>
class ExpressionEvaluator
{
public:
	//Конструктор по умолчанию
	ExpressionEvaluator();
	//Переопределяемый метод подсчета результата
	virtual double Calculate();
	//Переопределяемый метод вывода лога на экран
	virtual void LogToScreen();
	//Переопределяемый метод сохранения лога в файл
	virtual void LogToFile(const std::string filename);
	//Переопределяемый метод сортировки
	virtual void Shuffle();
	//Переопределяемый метод перестановки местами
	virtual void Shuffle(int i, int j);
	//Переопределяемый метод установки операндов
	virtual double setOperand(double* array, int size);
	//Переопределяемый метод установки операндов
	virtual double setOperand(int i, double value);
	//Виртуальный деконструктор
	virtual ~ExpressionEvaluator() {};
};

