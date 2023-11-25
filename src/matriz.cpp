#include "../include/matriz.hpp"

Matriz::Matriz(unsigned int newA00, unsigned int newA01, unsigned int newA10, unsigned int newA11) {
	a00 = newA00;
	a01 = newA01;
	a10 = newA10;
	a11 = newA11;
}

unsigned int Matriz::getA00() {
	return a00;
}

unsigned int Matriz::getA01() {
	return a01;
}

unsigned int Matriz::getA10() {
	return a10;
}

unsigned int Matriz::getA11() {
	return a11;
}

void Matriz::atualizaValores(unsigned int newA00, unsigned int newA01, unsigned int newA10, unsigned int newA11) {
	a00 = newA00;
	a01 = newA01;
	a10 = newA10;
	a11 = newA11;
}

void Matriz::transformaVetor(Vetor* vetor) {
	unsigned int newX = vetor->getX() * a00 + vetor->getY() * a01;
	unsigned int newY = vetor->getX() * a10 + vetor->getY() * a11;
	vetor->setX(newX);
	vetor->setY(newY);
}

void Matriz::calculaProduto(Matriz *a, Matriz *b, Matriz *resultado) {
	unsigned int resultA00 = a->getA00() * b->getA00() + a->getA01() * b->getA10();
	unsigned int resultA01 = a->getA00() * b->getA01() + a->getA01() * b->getA11();
	unsigned int resultA10 = a->getA10() * b->getA00() + a->getA11() * b->getA10();
	unsigned int resultA11 = a->getA10() * b->getA01() + a->getA11() * b->getA11();
	resultado->atualizaValores(resultA00, resultA01, resultA10, resultA11);
}
