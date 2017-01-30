#include <iostream>
using namespace std;

class CMatrix {
  private:
	int M, N;
	char** matrix;
  public:
	CMatrix(istream &is) {
		is >> N >> M;

		matrix = new char*[N];
		for (int n = 0; n < N; n++) {
			matrix[n] = new char[M];
			for (int m = 0; m < M; m++)
				matrix[n][m] = '-';
		}

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> matrix[n][m];
			}
		}
	}

	~CMatrix() {
		for (int n = 0; n < N; n++) {
			delete [] matrix[n];
		}
		delete [] matrix;
	}

	void spread(int n, int m, bool** isSurrounded) {
		if (n < 0 || m < 0 || n >= N || m >= M) return;
		if (matrix[n][m] != 'O') return;
		if (isSurrounded[n][m] == false) return;

		isSurrounded[n][m] = false;

		spread(n - 1, m, isSurrounded);
		spread(n + 1, m, isSurrounded);
		spread(n, m - 1, isSurrounded);
		spread(n, m + 1, isSurrounded);
	}

	void solve() {

		bool** isSurrounded;

		isSurrounded = new bool*[N];
		for (int n = 0; n < N; n++) {
			isSurrounded[n] = new bool[M];
			for (int m = 0; m < M; m++)
				isSurrounded[n][m] = true;
		}

		for (int n = 0; n < N; n++) {
			if (matrix[n][0] == 'O') spread(n, 0, isSurrounded);
			if (matrix[n][M-1] == 'O') spread(n, M-1, isSurrounded);
		}

		for (int m = 1; m < M-1; m++) {
			if (matrix[0][m] == 'O') spread(0, m, isSurrounded);
			if (matrix[N-1][m] == 'O') spread(N-1, m, isSurrounded);
		}

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (matrix[n][m] == 'O' && isSurrounded[n][m]) matrix[n][m] = 'X';
			}
		}

		for (int n = 0; n < N; n++) {
			delete [] isSurrounded[n];
		}
		delete [] isSurrounded;

	}

	friend ostream& operator<<(ostream &os, const CMatrix &x) {
		for (int n = 0; n < x.N; n++) {
			for (int m = 0; m < x.M; m++) {
				os << x.matrix[n][m] << " ";
			}
		}
		return os;
	}
};

int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		CMatrix problem = CMatrix(cin);
		problem.solve();
		cout << problem << endl;
	}

	return 0;
}