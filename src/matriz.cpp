#include "../include/matriz.hpp"

Matriz::Matriz(unsigned long int newA00, unsigned long int newA01, unsigned long int newA10, unsigned long int newA11) {
	a00 = newA00 % 100000000L;
	a01 = newA01 % 100000000L;
	a10 = newA10 % 100000000L;
	a11 = newA11 % 100000000L;
}

unsigned long int Matriz::getA00() {
	return a00;
}

unsigned long int Matriz::getA01() {
	return a01;
}

unsigned long int Matriz::getA10() {
	return a10;
}

unsigned long int Matriz::getA11() {
	return a11;
}

void Matriz::atualizaValores(unsigned long int newA00, unsigned long int newA01, unsigned long int newA10, unsigned long int newA11) {
	a00 = newA00 % 100000000L;
	a01 = newA01 % 100000000L;
	a10 = newA10 % 100000000L;
	a11 = newA11 % 100000000L;
}

void Matriz::transformaVetor(Vetor* vetor) {
	unsigned long int newX = vetor->getX() * a00 + vetor->getY() * a01;
	unsigned long int newY = vetor->getX() * a10 + vetor->getY() * a11;
	vetor->setX(newX % 100000000L);
	vetor->setY(newY % 100000000L);
}

void Matriz::calculaProduto(Matriz *a, Matriz *b, Matriz *resultado) {
	unsigned long int resultA00 = a->getA00() * b->getA00() + a->getA01() * b->getA10();
	unsigned long int resultA01 = a->getA00() * b->getA01() + a->getA01() * b->getA11();
	unsigned long int resultA10 = a->getA10() * b->getA00() + a->getA11() * b->getA10();
	unsigned long int resultA11 = a->getA10() * b->getA01() + a->getA11() * b->getA11();
	resultado->atualizaValores(resultA00 % 100000000L, resultA01 % 100000000L, resultA10 % 100000000L, resultA11 % 100000000L);
}
