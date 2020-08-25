#include <bits/stdc++.h>

using namespace std;

//typedef vector<char> vc;
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

int main(){
    const int TAM = 20;
    vi lista(TAM+1);//sentila
    numAleatorio(lista);
    //vc lista = {'c', 'h', 'e', 'w', 'b', 'a', 'c', 'c', 'a', '/'}; //sentila = '/'
    cout << "Nao ordenado: ";
    print(lista);
    quickSort(lista, 0, lista.size()-2);
    if(estaSort) {
        cout << "Ordenado:     ";
        print(lista);
    }
    else {
        cout << "Não foi ordenado\n";
    }
    return 0;
}
