#include <iostream>
#include <algorithm>
using namespace std;

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main() {

	int T, N, found;
	int B[2] = {0, 0};
	int* A;

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		A = new int[2 * N + 2];

		for (int i = 0; i < 2*N+2; i++) {
			cin >> A[i];
		}

		qsort (A, 2 * N + 2, sizeof(int), compare);

		found = 0;
		for (int i = 1; i < 2*N+2; i++) {
			if (A[i-1] == A[i]) i++;
			else B[found++] = A[i-1];
		}
		if (found < 2) B[found++] = A[2 * N + 1];

		if (B[0] > B[1]) {
			int tmp = B[0];
			B[0] = B[1];
			B[1] = tmp;
		}

		cout << B[0] << " " << B[1] << endl;

	}

	return 0;
}