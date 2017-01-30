#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int toInt(string s) {
	int tmp;
	istringstream(s) >> tmp;
	return tmp;
}

int main() {

	int T, a, b;
	string s;

	cin >> T;

	while (T--) {
		size_t i = 1;
		cin >> s >> a >> b;

		for ( ; i < s.size(); i++) {
			string p1, p2;

			p1 = s.substr(0, i);
			p2 = s.substr(i, s.size() - i);

			if (toInt(p1) % a == 0 && toInt(p2) % b == 0) {
				cout << p1 << " " << p2 << endl;
				i = 0;
				break;
			}
		}

		if (i > 0) {
			cout << -1 << endl;
		}
	}

	return 0;
}