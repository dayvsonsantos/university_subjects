#include <iostream>
#include <list>

using namespace std;

class Grafo{
    private:
        int n;
        int m;
        list <int> *adj;
    public:
        Grafo(){}
        Grafo(const int n);
        void insereAresta(int u, int v);
        void removerAresta(int u, int v);
        void mostrarGrafo();
        void destruidor();
};

Grafo::Grafo(const int n){
	this->n = n;
	this->adj = new list<int>[n+1];
	this->m = 0;
}

void Grafo::insereAresta(int u, int v){
    this->adj[u].push_back(v);
    this->adj[v].push_back(u);
}

void Grafo::removerAresta(int u, int v){
    this->adj[u].remove(v);
    this->adj[v].remove(u);
}

void Grafo::mostrarGrafo(){
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(list<int>::iterator it = this->adj[i].begin(); it != this->adj[i].end(); ++it){
            cout << *it << " -> ";
        }
        cout << "NULL" << endl;
    }
}

void Grafo::destruidor(){
    for(int i = 1; i <= this->n; i++) {
        this->adj[i].clear();
    }
    delete adj;
    this->n = this->m = 0;
}



template <typename T>
void bfs(int s){
    queue <T> filaDeVertices;

    filaDeVertices.push(s);

}
int main(){
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
