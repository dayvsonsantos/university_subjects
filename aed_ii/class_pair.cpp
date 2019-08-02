#include <iostream>

using namespace std;

template <class T, class L>
class Par {
	private:
		T primeiro;
		L segundo;
	public:
        Par() {};
		Par(T, L);
		void setPrimeiro(T);
		T getPrimeiro();
		void setSegundo(T);
		T getSegundo();
        void mostrarPar();
        void inserirPar(T, L);
};

template <class T, class L>
Par<T,L>::Par (T primeiro, L segundo) {
	this->primeiro = primeiro;
	this->segundo = segundo;
}

template <class T, class L>
void Par<T,L>::setPrimeiro (T primeiro) {
	this-> primeiro = primeiro;	
}

template <class T, class L>
T Par<T,L>::getPrimeiro () {
	return primeiro;
}

template <class T, class L>
void Par<T,L>::setSegundo (T segundo) {
	this-> segundo = segundo;	
}

template <class T, class L>
T Par<T,L>::getSegundo () {
	return segundo;
}

template <class T, class L>
void Par<T,L>::mostrarPar () {
	cout << primeiro << ", " << segundo << endl;
}

template <class T, class L>
void Par<T, L>::inserirPar (T primeiro, L segundo) {
    this->primeiro = primeiro;
    this->segundo = segundo;
}

int main () {
	Par <string, int> p("Accepted",10);
	p.mostrarPar();
	
	return 0;
}