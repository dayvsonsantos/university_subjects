#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

template <typename T>
T maiorElemento(vector <T> const A){
	T maior = -1;
	for(int i = 1; i < A.size(); i++){
		if(A[i] > maior){
			maior = A[i];
		}
	}
	return maior;
}

template <typename T>
int gerarRandomico(vector <T> &A) {
	int maior = -1;
	for(int i = 1; i < A.size(); i++) {
		A[i] = (rand() % 100);
	}
}

template <typename T>
void print(vector <T> const A) {
	for(int i = 1; i < A.size(); i++) {
		cout << setw(3) << A[i];
	}
	cout << endl;
}
  
template <typename T>
bool isSort(vector <T> const A) {
	for(int i = 1; i < A.size()-1; i++) {
		if( A[i] > A[i + 1] ) {
			return false;
		}
	}
	return true;
}

template <typename T>
void countSort(vector <T> const A, vector <T> &B, int const k) {
	vector <T> C(k+1);

	for(int i = 0; i <= k; i++){
		C[i] = 0;
	}

	for(int j = 1; j < A.size(); j++){
		C[A[j]]++;
	}

	for(int i = 1; i <= k; i++){
		C[i] += C[i-1];
	}

	for(int j = A.size()-1; j >= 1; j--){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}

int main() {

	srand( (unsigned) time(NULL) );

	vector <int> A(26), B(26);

	gerarRandomico(A);
	print(A);
	countSort(A, B, maiorElemento(A));

	cout << (isSort(B) ? "	Esta ordenado" : "	Não está ordenado") << endl;
	print(B);

	return 0;
}
