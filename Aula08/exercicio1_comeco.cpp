/*
 * Exemplo da aula 06/04/2019.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 05/04/2018
 * Adaptado em : 06/04/2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAXIMO 10

typedef struct Carro {
    string placa;
    int ano;
} Carro;

struct Pilha {
    Carro  carros[MAXIMO];
    int    contador;
};

void inicializar(Pilha *C) {
    C->contador = 0;
}

void push(Pilha *C, Carro empcar) {
	int posicao = C->contador;
    if (C->contador < MAXIMO) {
    	C->carros[posicao] = empcar;
        C->contador = C->contador + 1;
	}else {
        cout << "Erro: pilha cheia\n";		
	}
}

Carro pop(Pilha *C) {
    Carro retorno;
    int posicao;
    if (C->contador == 0) {
        cout << "Erro: pilha vazia\n";
        exit(-1);
    } else {
        C->contador--;
        posicao = C->contador;
        retorno = C->carros[C->contador];
        C->carros[posicao].placa = "";
        C->carros[posicao].ano = 0;
        return(retorno);
    }
}

void imprime_pilha(Pilha *C) {
    int x;
	for (x = C->contador; x > 0 ; x--)
		cout << C->carros[x-1].placa << endl;
	cout << endl;
}

int main() {
    Pilha pilhacarro;
    Carro carro_temp;
    
    inicializar(&pilhacarro);
    // Recebendo dados do usuário
	cout << "Digite a placa do carro" << endl;
    cin >> carro_temp.placa;
    cout << "Digite o ano do carro" << endl;
    cin >> carro_temp.ano;
    push(&pilhacarro, carro_temp);
    cout << "Digite a placa do carro" << endl;
    cin >> carro_temp.placa;
    cout << "Digite o ano do carro" << endl;
    cin >> carro_temp.ano;
    push(&pilhacarro, carro_temp);
    
    imprime_pilha(&pilhacarro);
    
    carro_temp.placa = "";
    carro_temp.ano = 0;
	
    
	cout << "Carro temporário - placa = " << carro_temp.placa << endl;
	cout << "Carro temporário - ano = " << carro_temp.ano << endl;
    
    carro_temp = pop(&pilhacarro);
    
    cout << "Carro temporário depois do pop- placa = " << carro_temp.placa << endl;
	cout << "Carro temporário depois do pop - ano = " << carro_temp.ano << endl;
	
	imprime_pilha(&pilhacarro);
	
}
