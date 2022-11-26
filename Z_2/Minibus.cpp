#include "Minibus.h"
Minibus::Minibus(double hundredConsume_) {
	hundredConsume = hundredConsume_;
}
double Minibus::consume(int distance) {
	return distance * (hundredConsume / 100);
}