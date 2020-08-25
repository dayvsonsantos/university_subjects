#include <iostream>
#include <vector>

using namespace std;

enum Color {branco, cinza, preto};

class Componente {
private:
	Color cor;
	int tamanhoLista;
	vector<double> v;
public:
	Componente(Color);
	void setCor(Color);
	Color getCor();
	void destroy();
	void insert(double);
	void print();
};

Componente::Componente(Color cor){
	this-> cor = cor;
	tamanhoLista = 0;
}

void Componente::setCor(Color cor){
	this-> cor = cor;
}

Color Componente::getCor(){
	return this-> cor;
}

void Componente::insert(double vertice) {
	v.push_back(vertice);
	tamanhoLista++;
}

void Componente::print() {
	if(tamanhoLista!=0){
		for (int j = 0; j < v.size(); j++) {
			cout << v[j] << " ";
		}
		cout << endl;	
	}else{
		cout << "Vazio\n";
	}
	
}

void Componente::destroy(){
	cor = branco;
	tamanhoLista = 0;
	v.clear();
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
	return 0;
}