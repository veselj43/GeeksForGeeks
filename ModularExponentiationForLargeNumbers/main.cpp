#include <iostream>
using namespace std;

class CLargeExpMod {
  protected:
	int A, B, C;
  public:
	CLargeExpMod(int a, int b, int c) : A(a), B(b), C(c) {
	}

	virtual int solve() = 0;
};

class Naive : public CLargeExpMod {
  public:
	Naive(int a, int b, int c) : CLargeExpMod(a, b, c) {
	}

	int solve() {
		int res;
		res = A;
		while(--B) res = (res * A) % C;
		return res;
	}
};

class CSquareAndMultiple : public CLargeExpMod {
  public:
	CSquareAndMultiple(int a, int b, int c) : CLargeExpMod(a, b, c) {
	}

	int process(int val, int b) {
		int r;

		if (b == 0) return 1;

		r = process((val * val) % C, b/2);
		if (b % 2) r *= val;

		return r % C;
	}

	int solve() {
		return process(A%C, B);
	}
};

int main() {

	int T;
	cin >> T;

	while (T--) {
		int A, B, C;
		cin >> A >> B >> C;
		cout << CSquareAndMultiple(A, B, C).solve() << endl;
	}

	return 0;
}