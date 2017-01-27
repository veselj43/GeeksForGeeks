#include <iostream>
using namespace std;

void changeColor(int x, int y, int C, int K, int** matrix, int N, int M) {
	if (x < 0 || y < 0 || x >= N || y >= M) return;
	if (matrix[x][y] != C) return;

	matrix[x][y] = K;

	changeColor(x+1, y, C, K, matrix, N, M);
	changeColor(x-1, y, C, K, matrix, N, M);
	changeColor(x, y+1, C, K, matrix, N, M);
	changeColor(x, y-1, C, K, matrix, N, M);
}

int main() {

	int T, N, M;
	int** matrix;

	cin >> T;

	for (int t = 0; t < T; t++) {
		int x, y, K;

		cin >> N >> M;

		matrix = new int*[N];
		for (int n = 0; n < N; n++) {
			matrix[n] = new int[M];
			for (int m = 0; m < M; m++)
				matrix[n][m] = 0;
		}

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> matrix[n][m];
			}
		}

		cin >> x >> y >> K;

		changeColor(x, y, matrix[x][y], K, matrix, N, M);

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cout << matrix[n][m] << " ";
			}
		}
		cout << endl;

		for (int n = 0; n < N; n++) {
			delete [] matrix[n];
		}
		delete [] matrix;
	}

	return 0;
}