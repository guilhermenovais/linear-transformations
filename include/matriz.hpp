#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include "vetor.hpp"

class Matriz {
	private:
		unsigned int a00, a01, a10, a11;
	public:
		Matriz(unsigned int newA00, unsigned int newA01, unsigned int newA10, unsigned int newA11);
		unsigned int getA00();
		unsigned int getA01();
		unsigned int getA10();
		unsigned int getA11();
		void atualizaValores(unsigned int newA00, unsigned int newA01, unsigned int newA10, unsigned int newA11);
		void transformaVetor(Vetor* vetor);
		static void calculaProduto(Matriz* a, Matriz* b, Matriz* resultado);
};

#endif // MATRIZ_HPP
