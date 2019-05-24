/*
 * Brincando com listas dinâmicas
 *
 * Um pequeno mimo para vocês, queridos alunos, avançarem nesta difícil jornada.
 *
 * 
 * Monitor: André Ré
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 24/05/2019
 */
 #include <iostream>
 #include <stdlib.h>

using namespace std;

typedef struct {
    string nome;
    int idade;
}ELEMENTO;

 typedef struct NO{
 	ELEMENTO aluno;
 	struct NO* proximo;
 }*LISTA;



 LISTA inicializar(LISTA lista_de_candidados){
 	// lista_de_candidados = (LISTA) malloc( sizeof(NO) );
  lista_de_candidados = new NO;
 	lista_de_candidados->proximo = NULL;
 	return lista_de_candidados;
 }

 LISTA cadastrar_candidato(LISTA lista_de_candidados){
     ELEMENTO novo_candidato;
     cout << "Digite o nome do vestibulando " << endl;
     cin >> novo_candidato.nome;
     cout << "Digite a idade do vestibulando " << endl;
     cin >> novo_candidato.idade;
     LISTA aux = new NO;
  	 aux->aluno = novo_candidato;
  	 aux->proximo  = lista_de_candidados;
     lista_de_candidados = aux;
     return lista_de_candidados;
 }

 void mostrar_inscritos(LISTA lista_de_candidados){
    LISTA no = lista_de_candidados;
 	while(no != NULL){
        if (no->proximo != NULL) {
            cout <<"CANDIDATO: " << no->aluno.nome << "\n ";
        }

 		no = no->proximo;
 	}
 	cout << endl;
 }
/*
 ELEMENTO dequeue(){
    ELEMENTO temp;
    temp.nome = "";
    temp.idade = -1;
    if(fila->prox == NULL ) {
        cout << "Nenhum cliente na fila";
    } else {
        FILA noAnterior = fila;
        FILA noAtual = fila;
     	while(noAtual->prox != NULL){
     		noAnterior = noAtual;
     		noAtual = noAtual->prox;
     	}
     	noAnterior->prox = NULL;
        temp = noAnterior->cliente;
     	free(noAnterior);
    }
    return temp;
 }
*/
 int numero_de_inscritos(LISTA lista_de_candidados){
     LISTA lista_local = lista_de_candidados;
 	int cont = 0;
 	while(lista_local != NULL){
 		lista_local = lista_local->proximo;
        cont++;
 	}
 	return (cont - 1);
 }

 void destruir(LISTA lista_de_candidados){
    if(lista_de_candidados->proximo != NULL ) {
        LISTA noProximo = lista_de_candidados;
        while(noProximo->proximo != NULL){
            cout << "| " << noProximo->aluno.nome;
            cout << " - " << noProximo->aluno.idade << endl;
            lista_de_candidados = noProximo->proximo;
            noProximo->proximo = NULL;
            delete noProximo;
            noProximo = lista_de_candidados;
     	}
      delete lista_de_candidados;
    }
 }

 int buscarFila(LISTA lista_de_candidados, string candidato){
     LISTA noProximo = lista_de_candidados;
     int cont = numero_de_inscritos(lista_de_candidados);
     while(noProximo != NULL){
         if (candidato == noProximo->aluno.nome) {
             return cont;
         }
         cont--;
         noProximo = noProximo->proximo;
     }
     return cont;
 }

 int main(){
     LISTA lista_de_candidados;
     char escolha = 'x';
     ELEMENTO candidado;
     lista_de_candidados = inicializar(lista_de_candidados);
     do {
           cout << "\n********************************\n";
           cout << "Digite uma letra\n\n";
           cout << "i \t Cadastrar candidato\n";
           cout << "a \t Validar inscricao\n";
           cout << "e \t Encontrar candidato \n";
           cout << "p \t Listar Candidatos \n";
           cout << "q \t Encerrar .\n\n\n";
           cin >> escolha;
           if(escolha == 'i' || escolha == 'I'){
               lista_de_candidados = cadastrar_candidato(lista_de_candidados);
           }
           if(escolha == 'a' || escolha == 'A'){
              cout << "Lamento, funcionalidade não implementada" << endl;
           }
           if(escolha == 'e' || escolha == 'E'){
               string candidato_procurado;
               cout << " Digite o nome do cliente procurado : " << endl;
               cin >> candidato_procurado;
               cout << "O candidato "<< candidato_procurado ;
               cout << " encontra-se na posicao "<< buscarFila(lista_de_candidados, candidato_procurado);
               cout << " da fila" << endl;
           }
           if(escolha == 'p' || escolha == 'P'){
               cout << "Candidatos inscritos: " << numero_de_inscritos(lista_de_candidados) << endl;
               mostrar_inscritos(lista_de_candidados);
           }
       } while( escolha != 'q');

     destruir(lista_de_candidados);
     return 0;
 }
