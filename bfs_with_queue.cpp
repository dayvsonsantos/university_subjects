#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
#define MAXIMO (int)1e6
#define INF (int)1e9

using namespace std;

enum Cor {branco = 0, preto = 1};

typedef int Vertice;
typedef double Peso;

template <typename T>
class No {
	public:
		T dado;
		No<T> *prox;
};

template <typename T, typename L>
class Par {
    private:
        T primeiro;
        L segundo;
    public:
        Par(){};
        Par(T primeiro, L segundo);
        T getPrimeiro();
        void setPrimeiro(T primeiro);
        L getSegundo();
        void setSegundo(L segundo);
        void mostrarPar();
};

template <typename T, typename L>
Par<T,L>::Par(T primeiro, L segundo){
    this->primeiro = primeiro;
    this->segundo = segundo;
}

template <typename T, typename L>
void Par<T,L>::mostrarPar(){
    cout << "[" << primeiro <<", " << segundo << "]";
}

template <typename T, typename L>
T Par<T,L>::getPrimeiro() {
    return primeiro;
}

template <typename T, typename L>
void Par<T,L>::setPrimeiro(T primeiro) {
    this->primeiro = primeiro;
}

template <typename T, typename L>
L Par<T,L>::getSegundo() {
    return segundo;
}


template <typename T>
class Fila {
	private:
		No<T> *inicio, *fim;
	public:
		Fila(T);
		void enfileirar(T);
		void desenfileirar();
		void mostrar();
		bool vazia();
		T retirarFila();
};

template <typename T>
Fila<T>::Fila(T elemento) {
	inicio = (No<T>*)malloc(sizeof(No<T>));
	inicio->dado = elemento;
	inicio->prox = NULL;
}

template <typename T>
void Fila<T>::enfileirar(T valor) {
	if(inicio->prox == NULL) fim = inicio;
	fim->prox = (No<T>*)malloc(sizeof(No<T>));  //campo proximo vira um novo nó
	fim = fim->prox; //o fim passa a apontar p/ o novo nó
	fim->prox = NULL; 
	fim->dado = valor;
}

template <typename T>
void Fila<T>::desenfileirar() {
	if(!vazia()){
		No<T> *aux = inicio->prox;
		inicio->prox = aux->prox;
		delete aux;
	}
}

template <typename T>
bool Fila<T>::vazia() {
	return (inicio->prox == NULL);
}

template <typename T>
void Fila<T>::mostrar() {
	No<T> *atual = inicio->prox;
	while(atual != NULL){
		cout << atual->dado << " ";
		atual = atual->prox;
	}
	cout << endl;
}

template <typename T>
T Fila<T>::retirarFila() {
	if(!vazia()){
		No<T> *aux = inicio->prox;
		T elemento = aux->dado;
		inicio->prox = aux->prox;
		delete aux;
		return elemento;
	}
}

class Grafo {
    private:
        vector <Par <Vertice, Peso> > *adj;
        int tamanho;
        int ordem;
    public:
        vector <Par <Vertice, Peso> >* obterAdj();
		Grafo(int);
        void inserirAresta(Vertice, Vertice, Peso);
        void mostraGrafo();
        int getOrdem();
        int getTamanho();
};

Grafo::Grafo(int ordem) {
    this->ordem = ordem;
    adj = new vector <Par<Vertice, Peso> >[ordem + 1];
	tamanho = 0;
}

void Grafo::inserirAresta(Vertice u, Vertice v, Peso peso = 1) {
    Par<Vertice,Peso> p(v, peso);
    adj[u].push_back(p);
	
	p.setPrimeiro(u);
    adj[v].push_back(p);
	
	tamanho++;
}

void Grafo::mostraGrafo() {
    for(int i = 1; i <= ordem; i++) {
        cout << i << ": ";
        for(int j = 0; j < adj[i].size(); j++) {
            adj[i][j].mostrarPar();
            cout << " ";
        }
        cout << "\n";
    }
}

int Grafo::getOrdem() {
    return ordem;
}

int Grafo::getTamanho() {
    return tamanho;
}

vector <Par <Vertice, Peso> >* Grafo::obterAdj() {
	return adj;
}
void BFS (Grafo &grafo) {
	vector <Peso> distancia;
	distancia.assign(MAXIMO,INF);
	
	vector <Cor> cor;
	cor.assign(MAXIMO,branco);
	
	Fila<Vertice> fila(0);
	fila.enfileirar(1);
	distancia[1] = 0;
	cor[1] = preto;
	
	vector <Par <Vertice, Peso> >* adj = grafo.obterAdj(); 
	while (!fila.vazia()) {
		Vertice u = fila.retirarFila();	
		
		for (int j = 0; j < adj[u].size(); j++) {
			
			Vertice v = adj[u][j].getPrimeiro();
			cout << v << " ";
			if (distancia[v] == INF) {
				distancia[v] = distancia[u] + 1;
				fila.enfileirar(v);
			}
		}
		cout << endl;
	}
}

int main () {
    Par <string, int> par("Accepted",10);
	par.mostrarPar();
    
    cout << endl;
    
    Fila<int> fila(0);// se nao iniciar o construtor com algum valor nao funciona
	fila.enfileirar(656);
	fila.enfileirar(13);
	fila.mostrar();
    	
	Grafo grafo(4);

    grafo.inserirAresta(1, 2);
    grafo.inserirAresta(1, 3);
    grafo.inserirAresta(1, 4);
    grafo.inserirAresta(2, 3);
    grafo.inserirAresta(3, 4);
    grafo.inserirAresta(4, 1);

    grafo.mostraGrafo();
	
	BFS(grafo);
    
    return 0;
}