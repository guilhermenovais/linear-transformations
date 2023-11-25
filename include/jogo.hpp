#ifndef JOGO_HPP
#define JOGO_HPP

#include "seg_tree.hpp"

class Jogo {
	private:
		unsigned int instanteMax;
		SegTree* intervalos;
	public:
		Jogo(unsigned int qtdIntantes);
		~Jogo();
		void atualiza(unsigned int instante, Matriz* novaTransformacao);
		void consulta(unsigned int nascimento, unsigned int morte, Vetor* vetor);
};

#endif // JOGO_HPP
