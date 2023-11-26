#include "../include/vetor.hpp"

Vetor::Vetor(unsigned long int newX, unsigned long int newY) {
	x = newX;
	y = newY;
}

unsigned long int Vetor::getX() {
	return x;
}

unsigned long int Vetor::getY() {
	return y;
}

void Vetor::setX(unsigned long int newX) {
	x = newX;
}

void Vetor::setY(unsigned long int newY) {
	y = newY;
}
