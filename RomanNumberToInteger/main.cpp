#include <iostream>
using namespace std;

int getSimpleValue(char x) {
	switch(x) {
		case 'I': return    1;
		case 'V': return    5;
		case 'X': return   10;
		case 'L': return   50;
		case 'C': return  100;
		case 'D': return  500;
		case 'M': return 1000;
	}
	return -1;
}

int main() {

	int T;
	cin >> T;

	while (T--) {
		string RN;
		int result, v1, v2;

		cin >> RN;

		result = 0;
		v1 = getSimpleValue(RN[0]);

		for (size_t i = 1; i < RN.size(); i++) {
			v2 = getSimpleValue(RN[i]);
			result += (v1 < v2) ? -v1 : v1;
			v1 = v2;
		}

		result += v1;

		cout << result << endl;
	}

	return 0;
}