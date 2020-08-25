#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
#define NIL 0

using namespace std;

enum Cor {branco, cinza, preto};

class Vertice{
    public:
        int d;
        Cor cor;
        list <int> conexoes;
        void mostrarVertice();
};

void Vertice::mostrarVertice(){
    for(list<int>::iterator i = this->conexoes.begin(); i != this->conexoes.end(); ++i){
        cout << *i << " -> ";
    }
    cout << "NULL" << endl;
}

class Grafo{
    private:
        int n;
        int m;
        vector <Vertice> adj;

    public:
        Grafo(int n);
        void insereAresta(int u, int v);
        void removeAresta(int u, int v);
        void mostrarGrafo();
        vector <int> BFS(int s);
};

Grafo::Grafo(int n){
    this->n = n;
    this->m = 0;
    this->adj.resize(n+1);
}

void Grafo::insereAresta(int u, int v){
    this->adj[u].conexoes.push_back(v);
    this->adj[v].conexoes.push_back(u);
}

void Grafo::removeAresta(int u, int v){
    this->adj[u].conexoes.remove(v);
    this->adj[v].conexoes.remove(u);
}

void Grafo::mostrarGrafo(){
    for(int i = 1; i <= this->n; i++){
        cout << i << ": ";
        this->adj[i].mostrarVertice();
    }
}

vector <int> Grafo::BFS(int s){

    vector <int> treeBfs(this->n+1);
    queue <int> q;
    int u;
    int v;

    for(int i = 1; i <= this->n; i++){
        this->adj[i].cor = branco;
        this->adj[i].d = INT_MAX;
        treeBfs[i] = NIL;
    }

    this->adj[s].cor = cinza;
    this->adj[s].d = 0;

    q.push(s);

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(list<int>::iterator it = this->adj[u].conexoes.begin(); it != this->adj[u].conexoes.end(); it++){
            v = *it;
            if(this->adj[v].cor == branco){
                this->adj[v].cor = cinza;
                this->adj[v].d = this->adj[u].d+1;
                treeBfs[v] = u;
                q.push(v);
            }
        }
        this->adj[v].cor = preto;
    }

    return treeBfs;
}

int main(){

    vector <int> treeOfBfs(5);
    Grafo g(4);
    int origem;


    cout << "Grafo g: " << endl;

    g.insereAresta(1, 2);
    g.insereAresta(2, 3);
    g.insereAresta(3, 4);
    g.insereAresta(4, 1);

    g.mostrarGrafo();

    origem = 2;

    treeOfBfs = g.BFS(origem);

    cout << endl;
    for(int i = 1; i <= 4; i++){
        cout << "Distancia da origem " << origem << " para o Vertice " << i << " : " <<  treeOfBfs[i] << endl;
    }
    cout << endl;

    return 0;
}
