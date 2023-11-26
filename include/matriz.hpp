#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include "vetor.hpp"

class Matriz {
	private:
		unsigned long int a00, a01, a10, a11;
	public:
		Matriz(unsigned long int newA00, unsigned long int newA01, unsigned long int newA10, unsigned long int newA11);
		unsigned long int getA00();
		unsigned long int getA01();
		unsigned long int getA10();
		unsigned long int getA11();
		void atualizaValores(unsigned long int newA00, unsigned long int newA01, unsigned long int newA10, unsigned long int newA11);
		void transformaVetor(Vetor* vetor);
		static void calculaProduto(Matriz* a, Matriz* b, Matriz* resultado);
};

#endif // MATRIZ_HPP
