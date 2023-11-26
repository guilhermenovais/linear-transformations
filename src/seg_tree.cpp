#include "../include/seg_tree.hpp"

SegTree::SegTree(unsigned int qtdInstantes) {
	tamanho = qtdInstantes * 4;
	transformacoes = new Matriz*[tamanho];
	for(int i = 0; i < tamanho; i++)
		transformacoes[i] = new Matriz(1, 0, 0, 1);
}

SegTree::~SegTree() {
	for(int i = 0; i < tamanho; i++) {
		delete transformacoes[i];
	}
	delete[] transformacoes;
}

void SegTree::update(unsigned int noAtual, unsigned int inicioIntervalo, unsigned int fimIntervalo, unsigned int indice, Matriz* novoValor) {
	if(indice < inicioIntervalo || indice > fimIntervalo) return;

	if(inicioIntervalo == fimIntervalo) {
		delete transformacoes[noAtual];
		transformacoes[noAtual] = novoValor;
		return;
	}

	unsigned int meio = (inicioIntervalo + fimIntervalo) / 2;
	unsigned int filhoEsquerda = 2 * noAtual;
	unsigned int filhoDireita = 2 * noAtual + 1;
	
	update(filhoEsquerda, inicioIntervalo, meio, indice, novoValor);
	update(filhoDireita, meio + 1, fimIntervalo, indice, novoValor);

	Matriz::calculaProduto(transformacoes[filhoEsquerda], transformacoes[filhoDireita], transformacoes[noAtual]);
}

void SegTree::atualizaTransformacao(unsigned int instante, Matriz* transformacao) {
	update(1, 0, tamanho / 4 - 1, instante, transformacao);
}

Matriz* SegTree::query(unsigned int noAtual, unsigned int inicioIntervalo, unsigned int fimIntervalo, unsigned int inicioBusca, unsigned int fimBusca) {
	if (fimBusca < inicioIntervalo || fimIntervalo < inicioBusca) {
		// Intervalo completamente fora da consulta
		return new Matriz(1, 0, 0, 1);
	}
	if (inicioBusca <= inicioIntervalo && fimIntervalo <= fimBusca) {
		// Intervalo completamente dentro da consulta
		return new Matriz(transformacoes[noAtual]->getA00(), transformacoes[noAtual]->getA01(), transformacoes[noAtual]->getA10(), transformacoes[noAtual]->getA11());
	}

	unsigned int meio = (inicioIntervalo + fimIntervalo) / 2;
	unsigned int filhoEsquerda = 2 * noAtual;
	unsigned int filhoDireita = 2 * noAtual + 1;

	// Recursivamente buscar nos filhos
	Matriz* matrizEsquerda = query(filhoEsquerda, inicioIntervalo, meio, inicioBusca, fimBusca);
	Matriz* matrizDireita = query(filhoDireita, meio + 1, fimIntervalo, inicioBusca, fimBusca);
	Matriz* resultado = new Matriz(1, 0, 0, 1);

	// Calcula produto
	Matriz::calculaProduto(matrizEsquerda, matrizDireita, resultado);
	delete matrizEsquerda;
	delete matrizDireita;

	return resultado;
}

Matriz* SegTree::getTransformacao(unsigned int inicio, unsigned int fim) {
	return query(1, 0, tamanho / 4 - 1, inicio, fim);
}
