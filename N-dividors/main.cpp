#include <iostream>
using namespace std;

int getNumberOfDividors(int n) {
	int count = 1;
	for (int i = 1; i <= n/2; i++) {
		if (n % i == 0) count++;
	}
	return count;
}

int main() {

	int T, a, b, n, count;

	cin >> T;

	while (T--) {
		cin >> a >> b >> n;

		count = 0;

		for (int i = a; i <= b; i++) {
			int x = getNumberOfDividors(i);
			if (x == n) count++;
			// cout << i << ": " << x << endl;
		}

		cout << count << endl;
	}


	return 0;
}