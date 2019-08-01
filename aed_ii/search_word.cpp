#include <iostream>

using namespace std;

void search_word(string &P, string &T) {
	int n = (int)P.size();
	int m = (int)T.size();
	for (int s = 0, i; s < m-n; s++) {
		for (i = 0; (i < n) && (P[i] == T[s + i]); i++);
		if (i == n) cout << P << endl;
	}
}

int main(int argc, char const *argv[]) {
	string b = "a vida eh bela!!!";
	string a = "vida";
	buscaPalavra(a, b);
	return 0;
}
