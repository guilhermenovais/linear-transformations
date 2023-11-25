#include "../include/jogo.hpp"

Jogo::Jogo(unsigned int qtdInstantes) {
	instanteMax = qtdInstantes;
	intervalos = new SegTree(qtdInstantes);
}

Jogo::~Jogo() {
	delete intervalos;
}

void Jogo::atualiza(unsigned int instante, Matriz* novaTransformacao) {
	if(instante >= instanteMax) throw "Instante inválido.";
	else intervalos->atualizaTransformacao(instante, novaTransformacao);
}

void Jogo::consulta(unsigned int nascimento, unsigned int morte, Vetor* vetor) {
	if(morte >= instanteMax) throw "Instante inválido.";
	Matriz* transformacao = intervalos->getTransformacao(nascimento, morte);
	transformacao->transformaVetor(vetor);
	delete transformacao;
}
