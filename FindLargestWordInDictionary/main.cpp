#include <iostream>
using namespace std;

int main() {

	int T;
	cin >> T;

	while (T--) {
		int size, best;
		string s;
		string* dict;

		cin >> size;
		dict = new string[size];
		for (int i = 0; i < size; i++) {
			cin >> dict[i];
		}
		cin >> s;

		best = -1;
		for (int i = 0; i < size; i++) {
			size_t n, k;
			k = 0;

			if (best >= 0 && dict[i].size() <= dict[best].size()) continue;

			for (n = 0; n < s.size(); n++) {
				if (dict[i][k] == s[n]) {
					k++;
					if (k == dict[i].size()) {
						best = i;
						break;
					}
				}
			}
		}

		cout << dict[best] << endl;

		delete [] dict;
	}

	return 0;
}