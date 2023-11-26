#include "../include/vetor.hpp"

Vetor::Vetor(unsigned long int newX, unsigned long int newY) {
	x = newX % 100000000L;
	y = newY % 100000000L;
}

unsigned long int Vetor::getX() {
	return x;
}

unsigned long int Vetor::getY() {
	return y;
}

void Vetor::setX(unsigned long int newX) {
	x = newX % 100000000L;
}

void Vetor::setY(unsigned long int newY) {
	y = newY % 100000000L;
}
