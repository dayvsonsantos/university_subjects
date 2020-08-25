
#include <iostream>

using namespace std;

class No {
	public:
		int dado;
		No *prox;
};

class Fila {
	private:
		No *inicio;
		No *fim;
	public:
		Fila();
		void inserir(int);
		void remover();
		void mostrar();
		bool vazia();
};

Fila::Fila() {
	inicio = new No();//inicio da fila é um nó neutro
	inicio->prox = NULL;
}

void Fila::inserir(int valor) {
	if(inicio->prox == NULL) fim = inicio;
	fim->prox = new No(); //campo proximo vira um novo nó
	fim = fim->prox; //o fim passa a apontar p/ o novo nó
	fim->prox = NULL; 
	fim->dado = valor;
}

void Fila::remover() {
	if(!vazia()){
		No *aux = inicio->prox;
		inicio->prox = aux->prox;
		delete aux;
	}
}

bool Fila::vazia() {
	return (inicio->prox == NULL);
}

void Fila::mostrar() {
	No *atual = inicio->prox;
	while(atual != NULL){
		cout << atual->dado << " ";
		atual = atual->prox;
	}
	cout << endl;
}

int main() {
	Fila a;
	a.inserir(1);
	a.inserir(11);
	a.inserir(111);
	a.mostrar();
	a.remover();
	a.mostrar();
	a.remover();
	a.remover();
	a.remover();
	return 0;
}
