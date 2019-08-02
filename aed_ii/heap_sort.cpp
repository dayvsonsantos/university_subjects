#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>
#define NIL -1


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
		cout << A[i] << " ";
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

int parent(int i) {
	return (int) (floor(i / 2));
}

int left(int i) {
	return (2 * i);
}

int right(int i ) {
	return (2 * i + 1);
}

template <typename T>
void maxHeap(vector <T> &A, int i, int heapSize) {
	int largest = NIL;
	int l = left(i);
	int r = right(i);

	if(l <= heapSize and A[l] > A[i]) largest =  l;

	else largest = i;

	if(r <= heapSize and A[r] > A[largest]) largest = r;

	if( largest != i) {
		swap(A[i], A[largest]);
		maxHeap(A, largest, heapSize);
	}
}


template <typename T>
void buildHeap(vector <T> &A, int &heapSize) {
	heapSize = (int) A.size()-1;
	for(int i = (int) ( floor(heapSize/2) ); i >= 1; i--){
		maxHeap(A, i, heapSize);
	}
}


template <typename T>
void heapSort(vector <T> &A) {
	int heapSize = 0;
	buildHeap(A, heapSize);
	int N = (int) A.size()-1;
	for(int i = N; i >= 2; i--){
		swap(A[1], A[i]);
		heapSize--;
		maxHeap(A, 1, heapSize);
	}
}

int main() {
	vector <int> A(11);
	gerarRandomico(A);
	print(A);
	heapSort(A);
	if(isSort(A)) {
		cout << "  Esta ordenado" << endl;
		print(A);
	}
	else {
		cout << "  Não está ordenado" << endl;
	}
	return 0;
}
