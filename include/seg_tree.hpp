#ifndef SEG_TREE_HPP
#define SEG_TREE_HPP

#include "matriz.hpp"

class SegTree {
	private:
		Matriz** transformacoes;
		unsigned int tamanho;
		void update(int noAtual, int inicioIntervalo, int fimIntervalo, int indice, Matriz* novoValor);
		Matriz* query(int noAtual, int inicioIntervalo, int fimIntervalo, int inicioBusca, int fimBusca);
	public:
		SegTree(unsigned int qtdInstantes);
		~SegTree();
		void atualizaTransformacao(unsigned int instante, Matriz* transformacao);
		Matriz* getTransformacao(unsigned int inicio, unsigned int fim);
};

#endif // SEG_TREE_HPP
