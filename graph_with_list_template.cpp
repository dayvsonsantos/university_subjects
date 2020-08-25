#include <iostream>
#include <list>

using namespace std;

//template <class a_type> class a_class {...};

template <class T> class Item {
    public:
        T elemento;
        Item () {}
        Item (T elemento) { this->elemento = elemento; }
        void mostra() {  cout << this->elemento << " -> ";  }  
};
 
template <class T> class No {
    public:
        Item item;
        No *prox;
        No() {}
};

template <class T> class LSE {
    private:
        No *prim, *ult;
        No* pred(No*);
        bool vazia();
    public:
        LSE();
        void insere(Item);
        void remove(No*, Item&);
        No* busca(Chave);
        void mostra();
};

template <class T> LSE<T>::LSE() {
    prim = new No(); // cabeça
    prim->prox = nullptr;
    ult = prim;
}


template <class T> void LSE<T>::insere(Item x) {
    ult->prox = new No();
    ult = ult->prox;
    ult->prox = nullptr;
    ult->item = x;
}

template <class T> bool LSE<T>::vazia() {
    return prim == ult;
}


template <class T> No* LSE<T>::pred(No* r) {
    No* p = prim;
    while (p->prox != r) {
        p = p->prox;
    }
    return p;
}

template <class T> void LSE<T>::remove(No* r, Item& x) {
    if (vazia() || r == nullptr || r == prim)
        cout << "impossível remover\n";
    else {
        x = r->item;
        No *p = pred(r);
        p->prox = r->prox;
        if (p->prox == nullptr) ult = p;
        delete r;
    }
}

template <class T> No* LSE<T>::busca(Chave k) {
    No *p = prim->prox;
    while (p != nullptr && p->item.codigo != k) {
        p = p->prox;
    }
    return p;
}


template <class T> void LSE<T>::mostra() {
    cout << "LISTA:\n";
    No *p = prim->prox;
    while (p != nullptr) {
        p->item.mostra();
        p = p->prox;
    }
    cout << "\n";
}

template <class T> class Grafo{
    private:
        int n;
        int m;
        list <T> *adj; 
        list <T> :: iterator it;

    public:
        Grafo(){}
        Grafo(const int n);
        void insereAresta(T u, T v);
        void removerAresta(T u, T v);
        void mostrarGrafo();
        //T getQtdeVertices();
        //void setQtdeVertices(int n);
        //T getQtdeArestas();
        //void setQtdeArestas(int m);
        //list *getAdj();
        //void setAdj();
        void destruidor();
};

//template<class a_type> void a_class<a_type>::a_function(){...}

template <class T> Grafo<T>::Grafo(const int n){
	//if (this->n == 0) destruidor();
	this->n = n;
	this->adj = new list<T>[n+1];
	this->m = 0;
}

template <class T> void Grafo<T>::insereAresta(T u, T v){
    this->adj[u].push_back(v);
    this->adj[v].push_back(u);
}

template <class T> void Grafo<T>::removerAresta(T u, T v){
    this->adj[u].remove(v);
    this->adj[v].remove(u);
}

template <class T> void Grafo<T>::mostrarGrafo(){
    for(this->it=this->adj[i].begin(); this->it!=this->adj[i].end(); ++this->it){
        cout << *it << " -> ";
    }
    cout << "NULL" << endl;
}

template <class T> void Grafo<T>::destruidor(){
    for(int i = 1; i <= this->n; i++) {
        this->adj[i].clear();
    }
    delete adj;
    this->n = this->m = 0;
}

/*
T Grafo::getQtdeVertices() {
	return this->n;
}

void Grafo::setQtdeVertices(int n) {
	this->n = n;
}

T Grafo::getQtdeArestas() {
	return this->m;
}

void Grafo::setQtdeArestas(int m) {
	this->m = m;
}

list* Grafo::getAdj() {
	return this->adj;
}

void setAdj() {

}
*/
int main()
{
    //a_class<int> an_example_class;
    Grafo g(4);
    g.insereAresta(1, 2);
    g.insereAresta(2, 3);
    g.insereAresta(3, 4);
    g.insereAresta(4, 1);

    g.mostrarGrafo();

    g.removerAresta(3, 4);

    g.mostrarGrafo();

    return (0);
}
