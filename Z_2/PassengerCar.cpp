#include "PassengerCar.h"

PassengerCar::PassengerCar(double hundredConsume_){
	hundredConsume = hundredConsume_;
}

double PassengerCar::consume(int distance){
	return distance * (hundredConsume/100);
}