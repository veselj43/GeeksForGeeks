#include <iostream>
using namespace std;

int check(int l, int r, const string &S) {
	while(l < r) {
		cout << l << "\t" << r << endl;
		if (S[l] != S[r]) 
			return 1 + min(check(l+1, r, S), check(l, r-1, S));
		l++;
		r--;
	}
	return 0;
}

int main() {

	int T;
	cin >> T;

	while(T--) {
		string S;
		cin >> S;

		cout << check(0, S.size() - 1, S) << endl;
	}

	return 0;
}