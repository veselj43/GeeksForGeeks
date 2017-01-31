#include <iostream>
#include <string>
using namespace std;

class CSolver {
private:
	string A, B;
public:
	CSolver(istream &is) {
		cin >> A >> B;
	}

	int solve(size_t posA = 0, size_t posB = 0) {
		int counter;
		size_t found;

		if (posB == B.size()) return 1;

		if ((found = A.find(B[posB], posA)) == string::npos) return 0;

		counter = solve(found + 1, posB) + solve(found + 1, posB + 1);

		return counter;
	}
};

int main() {

	int T;
	cin >> T;

	while (T--) {
		string A, B;
		CSolver problem = CSolver(cin);
		cout << problem.solve() << endl;
	}

	return 0;
}