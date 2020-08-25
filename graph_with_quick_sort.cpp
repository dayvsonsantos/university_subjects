#include <bits/stdc++.h>

using namespace std;

typedef int Vertice;
typedef double Peso;

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

class Grafo {
private:
    vector <Par<Vertice, Peso> > *adj;
    int tamanho;
    int ordem;
public:
    Grafo(int);
    void inserirAresta(Vertice, Vertice, Peso);
    void mostraGrafo();
    int getOrdem();
	int getTamanho();
	 vector <Par <Vertice, Peso> >* obterAdj();
};

Grafo::Grafo(int ordem) {
    this->ordem = ordem;
    adj = new vector <Par<Vertice, Peso> >[ordem + 1];
	tamanho = 0;
}

void Grafo::inserirAresta(Vertice u, Vertice v, Peso peso = 1) {
    Par<Vertice,Peso> p(v, peso);
    adj[u].push_back(p);
	
	p.setPrimeiro(u);
    adj[v].push_back(p);
	
	tamanho++;
}

void Grafo::mostraGrafo() {
    for(int i = 1; i <= ordem; i++) {
        cout << i << ": ";
        for(int j = 0; j < adj[i].size(); j++) {
            adj[i][j].mostrarPar();
            cout << " ";
        }
        cout << "\n";
    }
}

int Grafo::getOrdem() {
    return ordem;
}

int Grafo::getTamanho() {
    return tamanho;
}

vector <Par <Vertice, Peso> >* Grafo::obterAdj() {
	return adj;
}

typedef vector<int> vi;

void numAleatorio(vi &items) {
    srand( (unsigned)time(NULL) );
    for(int i = 0; i < items.size()-1; i++)
        items[i] = rand()%100;
}

void print(vi &items) {
    for(int i = 0; i < items.size()-1; i++)
        cout << setw(3) << items[i];
    cout << endl;
}

bool estaSort(vi &items){
    for(int i = 0; i < items.size()-1; i++)
        if(items[i] > items[i+1])
            return false;
    return true;
}

int particao(vi &items, int p, int r) {
    int x = items[p];
    int tmp = items[r + 1];
    int i = p;
    int j = r + 1;
    items[r + 1] = x;
    while(true) {
        do i++; while(items[i] < x);
        do j--; while(items[j] > x);
        if(i < j) swap(items[i], items[j]);
        else {
            swap(items[p], items[j]);
            items[r + 1] = tmp;
            return j;
        }
    }
}

void quickSort(vi &items, int p, int r) {
    if(p < r) {
        int q = particao(items, p, r);
        quickSort(items, p, q - 1);
        quickSort(items, q + 1, r);
    }
}
bool cmp (vector <int> a, vector <int> b) {
    return a < b;
}

int main(){
    Grafo g(4);

    g.inserirAresta(1, 2);
    g.inserirAresta(1, 3);
    g.inserirAresta(1, 4);
    g.inserirAresta(2, 3);
    g.inserirAresta(3, 4);
    g.inserirAresta(4, 1);

    g.mostraGrafo();
    
    vector <Par <Vertice, Peso> >* lista = g.obterAdj();
    
    
    for(int i = 1 ;i < g.getOrdem(); i++) {
       /* cout << "Nao ordenado: ";
        print(lista[i]); 
        
        quickSort(lista[i], 0, lista[i].size()-2);     
        
        if(estaSort) {
            cout << "Ordenado:     ";
            print(lista[i]);
        }
        else {
            cout << "Não foi ordenado\n";
        }
*/  
        sort(lista[i], lista[i].end(), cmp);
    }
    
    return 0;
}