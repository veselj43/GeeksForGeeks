#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(long long x) {
	int l, r;
	string s;

	s = to_string(x);
	l = 0;
	r = s.size()-1;

	while (l < r)
		if (s[l++] != s[r--]) return false;

	return true;
}

int main() {

	int T;
	cin >> T;

	while (T--) {
		int N, from, to;
		long long a, b, bestB, best;
		cin >> N;

		best = 0;
		bestB = from = pow(10, N-1);
		to = from*10-1;

		for (a = to; a >= bestB; a--) {
			for (b = a; b >= from; b--) {
				long long tmp = a*b;
				if (tmp < best) break;

				if (isPalindrome(tmp)) {
					best = tmp;
					bestB = b;
				}
			}
		}

		cout << best << endl;
	}

	return 0;
}