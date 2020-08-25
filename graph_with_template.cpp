template <class T> class Grafo{
    private:
        int n;
        int m;
        list <T> *adj;

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
    for(int i = 1; i <= n; i++){
        for(list <T>:: iterator it = this->adj[i].begin(); this->it != this->adj[i].end(); ++it){
            cout << *it << " -> ";
        }
        cout << "NULL" << endl;
    }
}

template <class T> void Grafo<T>::destruidor(){
    for(int i = 1; i <= this->n; i++) {
        this->adj[i].clear();
    }
    delete sadj;
    this->n = this->m = 0;
}

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
