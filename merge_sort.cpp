//#include <bits/stdc++.h>
//<climits>
//floor()

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

template <typename T>
void Merge(vector <T> &A, int p, int q, int r) {
	int n1 = q - p + 1,		n2 = r - q, 	i, j, k;
	vector <T> L(n1 + 2), 	R(n2 + 2);

	for(i = 1; i <= n1; i++) L[i] = A[p + i - 1];
	for(j = 1; j <= n2; j++) R[j] = A[q + j];

	L[n1 + 1] = R[n2 + 1] = CHAR_MAX;

	i = j = 1;

    for(k = p; k <= r; k++) A[k] = (L[i] <= R[j] ? L[i++] : R[j++]);
}

template <typename T>
void mergeSort(vector <T> &A, int p, int r) {
	if(p < r) {
		int q = (int) (floor((p + r)/2));
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

template <typename T>
void print(vector <T> &A){
	for(int i = 1; i < A.size(); i++)
		cout << A[i] << " ";
	cout << endl;
}

int main(){
	vector <char> lista = {'@','J', 'N', 'O', 'V', 'X', 'C', 'B', 'M' , 'L', 'E'};
	print(lista);
	int p = 1, r = (int) lista.size()-1;
	mergeSort(lista, p, r);
	print(lista);
	return 0;
}