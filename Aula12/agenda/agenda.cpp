#include <iostream>

using namespace std;


#define N 48

typedef struct{
    string hora;
    string compromisso;
} COMPROMISSO;

typedef struct{
    COMPROMISSO elementos[N];
    int numeroElementos;
} AGENDA;

void inicializarLista(AGENDA* lista){
	int x;
    lista->numeroElementos = 0;
    for(x = 0; x< N; x++) {
    	lista->elementos[x].hora = "";
    	lista->elementos[x].compromisso = "";
	}
}

void exibirLista(AGENDA* lista){
    int i;
    cout << "Compromissos: " << endl;
    for(i = 0 ; i < N; i++) {
        cout << " " << lista->elementos[i].hora << "  ";
        cout << " " << lista->elementos[i].compromisso << "  ";
        cout << " " << endl << "  ";
    }
    cout << endl;
}

int buscaSequencial(AGENDA* lista, COMPROMISSO registro){
    int i = 0;
    while(i < lista->numeroElementos){
        if(registro.hora == lista->elementos[i].hora) {
          return i;
        } else {
          i++;
        }
    }
    return -1;
}

bool inserirCompromisso(AGENDA* lista, COMPROMISSO registro, int i){
    int j;
    if((lista->numeroElementos == N) || (i < 0))
        return false;
    for(j = lista->numeroElementos; j > i; j--) {
        lista->elementos[j] = lista->elementos[j-1];
    }
    lista->elementos[i] = registro;
    lista->numeroElementos++;
    return true;
}

int main(int argc, char** argv) {
	AGENDA lista;
    COMPROMISSO registro;
    inicializarLista(&lista);
    
    registro.hora = "7:30";
    registro.compromisso = "Estrutura de Dados";
    inserirCompromisso(&lista, registro, 15);
    
    registro.hora = "7:00";
    registro.compromisso = "Acordar";
    inserirCompromisso(&lista, registro, 14);
    
    registro.hora = "10:00";
    registro.compromisso = "Tomar AQUELE café";
    inserirCompromisso(&lista, registro, 20);
    exibirLista(&lista);
    
	return 0;
}
