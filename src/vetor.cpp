#include "../include/vetor.hpp"

Vetor::Vetor(unsigned int newX, unsigned int newY) {
	x = newX;
	y = newY;
}

unsigned int Vetor::getX() {
	return x;
}

unsigned int Vetor::getY() {
	return y;
}

void Vetor::setX(unsigned int newX) {
	x = newX;
}

void Vetor::setY(unsigned int newY) {
	y = newY;
}
