#include <iostream>
#include <vector>
#define NIL -1

using namespace std;

enum Cor {branco, cinza, preto};

typedef int Vertice;
typedef double Peso;

//========================================== Fila ===============================================
template <typename T>
class No {
    private:
        T dado;
        No<T> *prox;
    public:
        T getDado();
        void setDado(T dado);
        No *getProx();
        void setProx(No *prox);
};

template <typename T>
T No<T>::getDado() {
    return dado;
}

template <typename T>
void No<T>::setDado(T dado) {
    this->dado = dado;
}

template <typename T>
No<T> *No<T>::getProx() {
    return prox;
}

template <typename T>
void No<T>::setProx(No *prox) {
    this->prox = prox;
}

template <typename T>
class Fila {
    private:
        No<T> *inicio;
        No<T> *fim;
    public:
        Fila();
        void enfileirar(T valor);
        T desenfileirar();
        void mostrarFila();
        bool vazia();
};

template <typename T>
Fila<T>::Fila() {
    inicio = new No<T>();
    inicio->setProx(NULL);
}

template <typename T>
void Fila<T>::enfileirar(T valor) {
    if(inicio->getProx() == NULL) fim = inicio;
    fim->setProx(new No<T>());
    fim = fim->getProx();
    fim->setProx(NULL);
    fim->setDado(valor);
}

template <typename T>
T Fila<T>::desenfileirar() {
    if(!vazia()){
        No<T> *aux = inicio->getProx();
        inicio->setProx(aux->getProx());
        return aux->getDado();
    }
}

template <typename T>
bool Fila<T>::vazia() {
    return (inicio->getProx() == NULL);
}


//========================================== Par ===============================================

template <typename T, typename L>
class Par {
    private:
        T prim;
        L seg;
    public:
        Par(){};
        Par(T prim, L seg);
        T getPrim();
        void setPrim(T prim);
        L getSeg();
        void setSeg(L seg);
        void mostrarPar();
};

template <typename T, typename L>
Par<T,L>::Par(T prim, L seg) {
    this->prim = prim;
    this->seg = seg;
}

template <typename T, typename L>
void Par<T,L>::mostrarPar(){
    cout << "[" << prim << ", " << seg << "]";
}

template <typename T, typename L>
T Par<T,L>::getPrim() {
    return prim;
}

template <typename T, typename L>
void Par<T,L>::setPrim(T prim) {
    this->prim = prim;
}

template <typename T, typename L>
L Par<T,L>::getSeg() {
    return seg;
}

template <typename T, typename L>
void Par<T,L>::setSeg(L seg) {
    this->seg = seg;
}


//========================================== quickSort ===============================================

int particao(vector <Par <int, double> > &itens, int p, int r) {
    Par <int, double> x(itens[p].getPrim(), itens[p].getSeg());
    Par<int, double> tmp(itens[r+1].getPrim(), itens[r+1].getSeg());

    int i = p;
    int j = r + 1;
    itens[r + 1] = x;

    while(true) {
        do i++; while(itens[i].getPrim() < x.getPrim());
        do j--; while(itens[j].getPrim() > x.getPrim());
        if(i < j) swap(itens[i], itens[j]);
        else {
            swap(itens[p], itens[j]);
            itens[r + 1] = tmp;
            return j;
        }
    }
}

void quickSort(vector <Par <int, double> > &itens, int p, int r) {
    if(p < r) {
        int q = particao(itens, p, r);
        quickSort(itens, p, q - 1);
        quickSort(itens, q + 1, r);
    }
}

//========================================== Grafo ===============================================
class Grafo {
    private:
        int n;
        vector < Par<Vertice, Peso> > *adj;
    public:
        Grafo(){};
        void criarGrafo(int n);
        void inserirAresta(Vertice u, Vertice v, Peso w);
        void removerAresta(Vertice u, Vertice v);
        void mostrarGrafo();
        vector <Par <Vertice, Peso> > getAdjdeU(Vertice u);
        int getVerticeAdjDeU(Vertice u, int i);
        void setVerticeAdjU(Vertice u, int i);
        double getPesoDoVerticeU(Vertice u, int i);
        void ordernarGrafo();
        int getN();
};

void Grafo::criarGrafo(int n) {
    this->n = n;
    adj = new vector < Par<Vertice, Peso> >[n + 1];
}

void Grafo::ordernarGrafo() {
    for (int i = 1; i <= n; i++) {
        Par <int, double> p(0, 0.0);
        adj[i].push_back(p);
        int f = (int)adj[i].size()-2;
        quickSort(adj[i], 0, f);
        adj[i].pop_back();
    }
}

void Grafo::inserirAresta(Vertice u, Vertice v, Peso w = 1) {
    Par<Vertice, Peso> p1(v, w);
    adj[u].push_back(p1);

    Par<Vertice, Peso> p2(u, w);
    adj[v].push_back(p2);
}

void Grafo::mostrarGrafo() {
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(int j = 0; j < adj[i].size(); j++) {
            adj[i][j].mostrarPar();
            cout << " ";
        }
        cout << "\n";
    }
}

vector <Par <Vertice, Peso> > Grafo::getAdjdeU(Vertice u) {
    return adj[u];
}

double Grafo::getPesoDoVerticeU(Vertice u, int i) {
    return adj[u][i].getSeg();
}

int Grafo::getVerticeAdjDeU(Vertice u, int i) {
    return  adj[u][i].getPrim();
}

int Grafo::getN(){
    return n;
}

//========================================== BFS ===============================================

bool inimigo(int inimigos[], int tam, int v){
    for (int i = 0; i < tam; i++)
        if(v == inimigos[i])
            return true;
    return false;
}


int* BFS(Grafo &g, const int s, int inimigos[], int &tam) {
    g.ordernarGrafo();
    Fila<int> fila;
    int *caminho = new int[g.getN()+1];
    int *cores = new int[g.getN()+1];
    int u, v;

    for (int i = 1; i <= g.getN(); ++i) {
        caminho[i] = NIL;
        cores[i] = branco;
    }

    fila.enfileirar(s);
    cores[s] = cinza;

    while (!fila.vazia()) {
        u = fila.desenfileirar();
        cout << u <<"\n" ;
        for (int i = 0; i < g.getAdjdeU(u).size(); i++) {
            v = g.getVerticeAdjDeU(u, i);
            if (cores[v] == branco && !inimigo(inimigos, tam, v)) {
                cout << v << " ";
                cores[v] = cinza;
                caminho[v] = u;
                fila.enfileirar(v);
            }
        }
        cout << "\n\n";
        cores[u] = preto;
    }
    return caminho;
}


//========================================== DFS ===============================================

void visita(Grafo &g, int cor[], int u, double& somaDosPesos) {
    cor[u] = cinza;
    for (int i = 0; i < g.getAdjdeU(u).size(); i++) {
        int v = g.getVerticeAdjDeU(u, i);
        if (cor[v] == branco) {
            somaDosPesos += g.getPesoDoVerticeU(u, i);
            visita(g, cor, v, somaDosPesos);
        }
    }
    cor[u] = preto;
}

double DFS(Grafo &g) {
    cout << "foi\n";
    g.ordernarGrafo();
    int *cores = new int[g.getN()+1];
    double somPeso = 0;
    for (int i = 1; i <= g.getN(); i++) {
        cores[i] = branco;
    }
    for (int i = 1; i <= g.getN(); i++) {
        if (cores[i] == branco){
            visita(g, cores, i, somPeso);
        }
    }
    return somPeso;
}

//========================================== main ===============================================

int main(){

    Grafo galaxia;
    double resultado = 0;
    double w;
    int N, M;
    int u, v;
    int n, m;
    int qtdInimigos;
    int _inimigo;
    int inicio;
    int destino;
    int *pred;

    //cout << "N M: ";
    cin >> N >> M;
    galaxia.criarGrafo(N);

    while (M--) {
        //cout << "u v: ";
        cin >> u >> v;
        galaxia.inserirAresta(u, v);
    }
    //galaxia.mostrarGrafo();
    //cout << "qtd_inimigoos: ";
    cin >> qtdInimigos;
    int *vInimigos = new int[qtdInimigos];

    for (int i = 0; i < qtdInimigos; i++) {
        //cout << "inimigos: ";
        cin >> _inimigo;
        vInimigos[i] = _inimigo;
        cout << vInimigos[i] << " ";
    }
    cout << "\n";
    //cout << "inicio destino: ";
    cin >> inicio >> destino;
    //galaxia.ordernarGrafo();
    pred = BFS(galaxia, inicio, vInimigos, qtdInimigos);

    for (int i = 1; i <= N; i++) {
        cout << pred[i] << " ";
    }
    Grafo sistemas[N+1];

    for (int i = 1; i <= N; i++) {
        //cout << "sistema: " << i << "\n";
        //cout << "n m: ";
        cin >> n >> m;
        sistemas[i].criarGrafo(n);

        while (m--) {
            //cout << "u v w: ";
            cin >> u >> v >> w;
            sistemas[i].inserirAresta(u, v, w);
        }
    }



    //cout << "foi\n";
    //cout << qtdInimigos << "\n";

    /*for (int i = destino; i != inicio; i = pred[i]) {
        resultado += DFS(sistemas[pred[i]]);
    }*/

    //resultado += DFS(sistemas[pred[inicio]]);

    cout << "\n\tresultado: " << resultado << "\n";
    return 0;
}
