#include <iostream>
using namespace std;

int main() {

	int T;
	cin >> T;

	while (T--) {
		string s;
		int count, state;
		cin >> s;

		count = 0;
		state = 0;

		for (size_t i = 0; i < s.size(); i++) {
			switch (state) {
				case 0:
					if (s[i] == '1')
						state = 1;
					break;
				case 1:
					if (s[i] == '0')
						state = 2;
					else if (s[i] != '1')
						state = 0;
					break;
				case 2:
					if (s[i] == '1') {
						state = 1;
						count++;
					}
					else if (s[i] != '0')
						state = 0;
					break;
			}
		}

		cout << count << endl;
	}

	return 0;
}