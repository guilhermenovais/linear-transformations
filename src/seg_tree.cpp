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

void SegTree::update(int noAtual, int inicioIntervalo, int fimIntervalo, int indice, Matriz* novoValor) {
	if (inicioIntervalo == fimIntervalo) {
		// Nó folha
		delete transformacoes[noAtual];
		transformacoes[noAtual] = novoValor;
	} else {
		int meio = (inicioIntervalo + fimIntervalo) / 2;
		int filhoEsquerda = 2 * noAtual;
		int filhoDireita = 2 * noAtual + 1;

		// Atualizar recursivamente os filhos
		if (indice <= meio) {
			update(filhoEsquerda, inicioIntervalo, meio, indice, novoValor);
		} else {
			update(filhoDireita, meio + 1, fimIntervalo, indice, novoValor);
		}

		// Atualizar o nó atual com a soma dos filhos
		Matriz::calculaProduto(transformacoes[filhoEsquerda], transformacoes[filhoDireita], transformacoes[noAtual]);
	}
}

void SegTree::atualizaTransformacao(unsigned int instante, Matriz* transformacao) {
	update(1, 0, tamanho - 1, instante, transformacao);
}

Matriz* SegTree::query(int noAtual, int inicioIntervalo, int fimIntervalo, int inicioBusca, int fimBusca) {
	if (fimBusca < inicioIntervalo || fimIntervalo < inicioBusca) {
		// Intervalo completamente fora da consulta
		return new Matriz(1, 0, 0, 1);
	}
	if (inicioBusca <= inicioIntervalo && fimIntervalo <= fimBusca) {
		// Intervalo completamente dentro da consulta
		return new Matriz(transformacoes[noAtual]->getA00(), transformacoes[noAtual]->getA01(), transformacoes[noAtual]->getA10(), transformacoes[noAtual]->getA11());
	}

	int meio = (inicioIntervalo + fimIntervalo) / 2;
	int filhoEsquerda = 2 * noAtual;
	int filhoDireita = 2 * noAtual + 1;

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
	return query(1, 0, tamanho - 1, inicio, fim);
}
