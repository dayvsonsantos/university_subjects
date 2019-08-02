#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

template <typename T>
void gerarRandomico(vector <T> &A) {
	for(int i = 1; i < A.size(); i++) {
		A[i] = (rand() % 100);
	}
}

template <typename T>
void print(vector <T> &A) {
	for(int i = 1; i < A.size(); i++) {
		cout << setw(3) << A[i];
	}
	cout << endl;
}

template <typename T>
bool isSort(vector <T> &A) {
	for(int i = 1; i < A.size()-1; i++) {
		if( A[i] > A[i + 1] ) {
			return false;
		}
	}
	return true;
}

template <typename T>
void shellSort(vector <T> &A) {

	int i, j, h = 1;

	const int N = A.size();

	while(h < N/3) h = 3 * h + 1;

	while(h >= 1) {

		for(i = h; i <= N-1; i++) {

			j = i;

			while(j >= h and A[j] < A[j - h]) {

				swap(A[j], A[j - h]);

				j = j - h;
			}
		}

		h = h/3;
	}
}

int main() {

	srand( (unsigned) time(NULL) );

	vector <int> A(26);

	gerarRandomico(A);
	print(A);
	shellSort(A);

	cout << (isSort(A) ? "	Esta ordenado" : "	Não está ordenado") << endl;
	print(A);
	return 0;
}
