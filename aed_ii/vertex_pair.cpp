#include <iostream>
#include <vector>
using namespace std;

typedef int Vertice;
typedef double Peso;

enum Cor{branco, cinza, preto};

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

template <typename T, typename L>
void Par<T,L>::setSegundo(L segundo) {
    this->segundo = segundo;
}

class Grafo {
private:
     vector <Par<Vertice, Peso> > *adj;
    int n;
    int m;
public:
    Grafo(int n);
    void inserirAresta(Vertice u, Vertice v, Peso p);
    void mostraGrafo();
    int getN();
};

Grafo::Grafo(int n) {
    this->n = n;
    adj = new vector <Par<Vertice, Peso> >[n+1];
}

void Grafo::inserirAresta(Vertice u, Vertice v, Peso peso = 1) {
    Par<Vertice,Peso> p(v, peso);
    adj[u].push_back(p);
}

void Grafo::mostraGrafo() {
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(int j = 0; j < adj[i].size(); j++) {
            adj[i][j].mostrarPar();
            cout << " ";
        }
        cout << "\n";
    }
}

int Grafo::getN() {
    return n;
}

vector <Par<Vertice, Par> > Grafo::getAdjDeU(Vertice u){
    return adj[u];
}

Vertice Grafo::getAdjdeUdeI(Vertice u, int i) {
    return adj[u][i].getPrimeiro();
}

void bfs(Grafo &g, int s) {
    vector <int> cores(g.getN()+1, branco);
    Fila<int> fila;
    int u;

    cores[s] = cinza;
    fila.enfileirar(s);

    while (!fila.vazia()) {

        u = fila.desenfilar();
        for (int i = 0; i < g.getAdjDeU(u).size(); i++) {
            v = g.getAdjdeUdeI(u, i);
            if (cores[v] == branco) {
                cores[v] = cinza;
                fila.enfileirar(v);
            }
            cores[u] = preto;
        }
    }

}

int main(int argc, char const *argv[]) {
    Grafo g(4);

    g.inserirAresta(1, 2);
    g.inserirAresta(1, 3);
    g.inserirAresta(1, 4);
    g.inserirAresta(2, 3);
    g.inserirAresta(3, 4);
    g.inserirAresta(4, 1);

    g.mostraGrafo();
	return 0;
}
