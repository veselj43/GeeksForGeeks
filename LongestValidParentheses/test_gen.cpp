#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

	int T = 5;
	int L = 100;

	srand (time(NULL));

	while (T--) {
		string in;
		in = "";
		for (int i = 0; i < L; i++)
			in += (rand()%2) ? "(" : ")";
		cout << in << endl;
	}

	return 0;
}