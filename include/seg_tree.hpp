#ifndef SEG_TREE_HPP
#define SEG_TREE_HPP

#include "matriz.hpp"

class SegTree {
	private:
		Matriz** transformacoes;
		unsigned int tamanho;
		void update(unsigned int noAtual, unsigned int inicioIntervalo, unsigned int fimIntervalo, unsigned int indice, Matriz* novoValor);
		Matriz* query(unsigned int noAtual, unsigned int inicioIntervalo, unsigned int fimIntervalo, unsigned int inicioBusca, unsigned int fimBusca);
	public:
		SegTree(unsigned int qtdInstantes);
		~SegTree();
		void atualizaTransformacao(unsigned int instante, Matriz* transformacao);
		Matriz* getTransformacao(unsigned int inicio, unsigned int fim);
};

#endif // SEG_TREE_HPP
