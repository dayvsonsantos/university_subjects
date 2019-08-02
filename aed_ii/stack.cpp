#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class No{
	public:
        T dado;
        No<T> *proximo;
};

template <typename T>
class Pilha {
    private:
        No<T> *topo, *novo, *atual;    
    public:
        Pilha(T);
        void empilhar(T);
        void desempilhar();
		T desempilharTopo();
		void vazia();
};

template <typename T>
Pilha<T>::Pilha (T elemento) {
    topo = (No<T>*)malloc(sizeof(No<T>));  
    topo->dado = elemento;
    topo->proximo = NULL;
}

template <typename T>
void Pilha<T>::empilhar (T elemento = 0) {
    novo = (No<T>*)malloc(sizeof(No<T>));
    novo->dado = elemento;
    novo->proximo = NULL;
    
    if(topo != NULL){
        novo->proximo = topo;
	}
	topo=novo;
}

template <typename T>
void Pilha<T>::desempilhar () {
	while(topo != NULL && topo->dado != 0){
		atual=topo;
		cout << topo->dado << endl;
		topo=topo->proximo;
		free(atual);
        break;
	}
}


template <typename T>
T Pilha<T>::desempilharTopo () {
	if(topo != NULL) {	
		T elemento = topo->dado;
		atual = topo;
		topo=topo->proximo;
		free(atual);
		return elemento;
	}
}

int main(){
	Pilha<int> p(0);// se nao iniciar o construtor com algum valor nao funciona
    p.empilhar(2);
    p.empilhar(233);
    p.empilhar(233454);
  
    cout<< p.desempilharTopo() << endl;
    cout<< p.desempilharTopo() << endl;
	cout<< p.desempilharTopo() << endl;
	return 0;
}
