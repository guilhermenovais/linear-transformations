#include <iostream>
#include <string>

#include "../include/jogo.hpp"

int main (int argc, char *argv[]) {
	std::string entrada;
	std::cin >> entrada;
	int qtdInstantes = std::stoi(entrada);
	Jogo jogo = Jogo(qtdInstantes);
	std::cin >> entrada;
	int qtdOperacoes = std::stoi(entrada);

	for(int i = 0; i < qtdOperacoes; i++) {
		std::cin >> entrada;
		if(entrada == "u") {
			std::cin >> entrada;
			unsigned int instante = std::stoi(entrada);
			std::cin >> entrada;
			unsigned int a00 = std::stoi(entrada);
			std::cin >> entrada;
			unsigned int a01 = std::stoi(entrada);
			std::cin >> entrada;
			unsigned int a10 = std::stoi(entrada);
			std::cin >> entrada;
			unsigned int a11 = std::stoi(entrada);
			Matriz* transformacao = new Matriz(a00, a01, a10, a11);
			jogo.atualiza(instante, transformacao);
		} else if(entrada == "q") {
			std::cin >> entrada;
			unsigned int nascimento = std::stoi(entrada);
			std::cin >> entrada;
			unsigned int morte = std::stoi(entrada);
			std::cin >> entrada;
			unsigned int x = std::stoi(entrada);
			std::cin >> entrada;
			unsigned int y = std::stoi(entrada);
			Vetor* vetor = new Vetor(x, y);
			jogo.consulta(nascimento, morte, vetor);
			std::cout << vetor->getX() % 100000000 << " " << vetor->getY() % 100000000 << "\n";
			delete vetor;
		}
	}
}
