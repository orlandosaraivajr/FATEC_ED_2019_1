#include <iostream>
using namespace std;

void naotroca(string n, string sn);
void troca(string *pontN, string *pontSN);

int main()
{
    string nome, sobrenome;

    cout<<"Digite seu Nome: ";
    cin>>nome;

    cout<<"Digite seu Sobrenome: ";
    cin>>sobrenome;

    cout<<endl;

    cout<<">>NAO TROCA"<<endl;
    naotroca(nome, sobrenome);
    cout<<"Main: "<<nome<<" "<<sobrenome;

    cout<<endl<<endl;

    cout<<">>TROCA"<<endl;
    troca(&nome, &sobrenome);
    cout<<"Main: "<<nome<<" "<<sobrenome;

    return 0;
}

void naotroca(string n, string sn){
    string aux;
    aux=n;
    n=sn;
    sn=aux;

    cout<<" Func: "<<n<<" "<<sn<<endl;

    return;
}

void troca(string *pontN, string *pontSN){
    string aux;
    aux=*pontN;
    *pontN=*pontSN;
    *pontSN=aux;

    cout<<"Func: "<<*pontN<<" "<<*pontSN<<endl;

    return;
}
