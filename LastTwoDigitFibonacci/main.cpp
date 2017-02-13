#include <stdio.h>
#include <iostream>
using namespace std;

int main() {

	int T;
	cin >> T;

	while (T--) {
		unsigned long long N;
		int actual, last, tmp;
		cin >> N;

		N %= 300;
		last = 0;
		actual = 1;

		for (unsigned long long i = 1; i < N; i++) {
			tmp = last;
			last = actual;
			actual += tmp;
			actual %= 100;
		}

		if (N == 0)
			cout << "00" << endl;
		else
			printf("%02d\n", actual);
	}

	return 0;
}