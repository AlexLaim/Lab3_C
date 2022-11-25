#include <iostream>
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "Subtractor.h"
#include "Summator.h"



int main()
{
	setlocale(LC_ALL, "ru");
	ExpressionEvaluator* evaluators[3];
	evaluators[0] = new Subtractor(4);
	double sub_array[4] = { 10.5, 2.5, -3, 1.5};
	evaluators[0]->setOperand(sub_array, 4);
	evaluators[1] = new CustomExpressionEvaluator(6);
	double cust_array[6] = {5, 15, -8, 1, 2, 3};
	evaluators[1]->setOperand(cust_array, 6);
	evaluators[2] = new Summator(3);
	evaluators[2]->setOperand(0, 1.5);
	evaluators[2]->setOperand(1, -4);
	evaluators[2]->setOperand(2, 2.5);
	for (size_t i = 0; i < 3; i++)
	{
		evaluators[i]->LogToFile("lab3.txt");
		evaluators[i]->LogToScreen();
		evaluators[i]->Calculate();
	}
	for (size_t i = 0; i < 3; i++)
	{
		evaluators[i]->Shuffle();
		evaluators[i]->Shuffle(0,1);
		if(i==0)
		std::cout << "\n\nShuffle\n\n";
		else 
		std::cout << "\n\nShuffle";
		evaluators[i]->Calculate();
	}
	for (size_t i = 0; i < 3; i++)
	{		
		evaluators[i]->~ExpressionEvaluator();
	}	
}