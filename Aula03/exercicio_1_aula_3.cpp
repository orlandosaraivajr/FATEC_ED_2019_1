/*
Exercício 1 - 09/03/2019

Prof. Me. Orlando Saraiva Jr
*/
#include <iostream>
#include <string>

using namespace std;

struct revisao {
    string local;
    int dia;
    int mes;
    int ano;
};

typedef struct carro {
    string modelo;
    string fabricante;
    int ano;
    revisao rev[5];
} CARRO;


int main(int argc, char *argv[]){

    int x;
    CARRO optimus;

	cout << "\nDigite o modelo do carro" << endl;
	cin >> optimus.modelo;
	cout << "\nDigite o fabricante do carro" << endl;
	cin >> optimus.fabricante;
	cout << "\nDigite o ano do carro" << endl;
	cin >> optimus.ano;
	
	for(x = 0; x<5; x++) {
		cout << "\nDigite o local da revisao" << endl;
		cin >> optimus.rev[x].local;
		cout << "\nDigite o dia" << endl;
		cin >> optimus.rev[x].dia;
		cout << "\nDigite o mes" << endl;
		cin >> optimus.rev[x].mes;
		cout << "\nDigite o ano" << endl;
		cin >> optimus.rev[x].ano;
	}
		
	cout << "\nO modelo digitado eh " << optimus.modelo;
	cout << "\nO fabricante digitado eh " << optimus.fabricante;
	cout << "\nO ano digitado eh " << optimus.ano;
	cout << "\n====================================" << endl;
	for(x = 0; x<5; x++) {
		cout << "\nO local da revisao =  " << optimus.rev[x].local;
		cout << "\nDia = " << optimus.rev[x].dia << "/"<< optimus.rev[x].mes << "/"<< optimus.rev[x].ano << "\n";	
	}
    return 0;
}


