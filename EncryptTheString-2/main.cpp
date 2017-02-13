#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

string intToHex(int x) {
	stringstream ss;
	ss << hex << x;
	return ss.str();
}

string reverse(string s) {
	string reversed = "";
	for (int i = s.size()-1; i >= 0; i--) reversed += s[i];
	return reversed;
}

int main() {

	int T;
	cin >> T;

	while (T--) {
		int counter;
		string s;
		cin >> s;

		counter = 1;
		for (int i = s.size()-1; i > 0; i--) {
			if (s[i] != s[i-1]) {
				cout << reverse(intToHex(counter)) << s[i];
				counter = 0;
			}
			counter++;
		}
		cout << reverse(intToHex(counter)) << s[0] << endl;
	}

	return 0;
}