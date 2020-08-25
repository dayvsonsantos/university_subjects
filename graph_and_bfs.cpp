#include <iostream>
#include <vector>
#include <list>
#include <climits>
#define NIL -1

using namespace std;

enum Cor {branco, cinza, preto};

class Vertice{
    public:
        int f;
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
        void BFS(int s);
        void DFS(int s);
        vector <Vertice> getAdj(Vertice v) {
            return adj[v];
        }

        void setAdj(vector <Vertice> adj){
            this->adj = adj;
        }
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

void Grafo::BFS(int s){

    vector <int> treeBfs(this->n+1);
    list <int> q;
    int u;

    for(int i = 1; i <= this->n; i++){
        this->adj[i].cor =  branco;
        this->adj[i].d   =  INT_MAX;
        treeBfs[i]       =  NIL;
    }

    this->adj[s].cor =  cinza;
    this->adj[s].d   =  0;

    q.push_front(s);

    while(!q.empty()){
        u = q.front();        q.pop_back();

        for(list<int>::iterator v = this->adj[u].conexoes.begin(); v != this->adj[u].conexoes.end(); ++v){
       
            if(this->adj[*v].cor == branco){
                this->adj[*v].cor =  cinza;
                this->adj[*v].d   =  this->adj[u].d+1;
                treeBfs[*v]       =  u;
                q.push_front(*v);
            }
        }

        this->adj[u].cor = preto;
    }

    cout << endl;
    for(int i = 1; i <= 4; i++){
         cout << "Pai de " << i << ": ";
        if(treeBfs[i] == -1){
            cout << "NIL";
        }else{
            cout << treeBfs[i];
        }

        cout << " Distância da origem: " << this->adj[i].d << endl;
    }
    cout << endl;
}




int main(){
    Grafo g(4);
  
    cout << "Grafo g: " << endl;

    g.insereAresta(1, 2);
    g.insereAresta(1, 4);
    g.insereAresta(4, 3);
    g.insereAresta(2, 3);

    g.mostrarGrafo();

    g.BFS(4);
    
    return 0;
}
