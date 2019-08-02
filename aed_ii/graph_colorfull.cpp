#include <iostream>
#include <vector>
#include <list>

using namespace std;

enum Color {branco, cinza, preto};
typedef Vertex int;

class Componente {
	private:
		Color cor;
		int tamanhoLista;
		vector<Vertex> lista;
	public:
		Componente(Color);
		void setTamanhoLista(int);
		int getTamanhoLista();
		void setCor(Color);
		Color getCor();
		void destroy();
		void insert(Vertex);
		void print();
};

Componente::Componente(Color cor) {
	this-> cor = cor;
	tamanhoLista = 0;
}

void Componente::setTamanhoLista(int tamanhoLista){
	this-> tamanhoLista = tamanhoLista;
}

int Componente::getTamanhoLista(){
	return this-> tamanhoLista;
}

void Componente::setCor(Color cor) {
	this-> cor = cor;
}

Color Componente::getCor() {
	return this-> cor;
}

void Componente::insert(Vertex vertice) {
	lista.push_back(vertice);
	tamanhoLista++;
}

void Componente::print() {
	if(tamanhoLista!=0){
		for (int j = 0; j < tamanhoLista; j++) {
			cout << lista[j] << " ";
		}
		cout << endl;	
	}else{
		cout << "Vazio\n";
	}
	
}

void Componente::destroy() {
	cor = branco;
	tamanhoLista = 0;
	lista.clear();
}

template <class T>
class Graph {
	private:
		int ordem, tamanho;
		list<Componente> *adj;
	public:
		Graph(int);
		~ Graph();
		
		void setOrdem();
		void setTamanho();
		
		T getOrdem();
		T getTamanho();

		void insertEdge(T,T);
		void printGraph();
		void destroyGraph();
};


Graph::Graph(int ordem) {
	this-> ordem = ordem;
	this-> tamanho = 0;
	this-> adj = new list<Componente>[ordem + 1];
}

template <class T>
void Graph::setOrdem(T n) {
	this-> ordem = n; 
}

template <class T>
void Graph::setTamanho(T m) {
	this-> tamanho = m;
}

T Graph::getOrdem() {
	return this-> ordem;
}

T Graph::getTamanho() {
	return this-> tamanho;
}

template <class T>
void Graph::insertEdge(T verticeU, T verticeV) {
	adj[verticeU].lista.insert(verticeV);
	adj[verticeV].lista.insert(verticeU);
	tamanho++;
}

void Graph::printGraph() {
	for (int i = 1; i <= ordem; i++) {
		cout << "v[" << i << "] = ";
		for(int j = 1; j <adj[i].lista.getTamanhoLista(); j++){
			adj[i].lista[j].print();	
		}
	}
}

void Graph::destroyGraph() {
	for (int i = 1; i <= ordem; i++) {
		adj[i].destroy();
	}
	delete adj;
	ordem = tamanho = 0;
}
int main() {
	Componente var(branco);
	cout << var.getCor() << endl;

	var.setCor(cinza);
	cout << var.getCor() << endl;

	var.setCor(preto);
	cout << var.getCor() << endl;

	var.print();
	
	var.insert(1);
	var.insert(2);
	var.insert(3);
	var.insert(4);
	var.insert(5.5);
	var.insert(6);

	var.print();

	Graph g(5);
	g(1,2);
	g(2,3);
	g(3,4);
	g.printGraph();

	return 0;
}