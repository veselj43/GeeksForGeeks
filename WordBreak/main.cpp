#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool beginsWith(string s1, string s2) {
	for (size_t i = 0; i < s1.size(); i++) 
		if (s1[i] != s2[i]) return false;
	return true;
}

int find(string S, const vector<string> dict) {
	if (S.empty()) return 1;

	for (size_t n = 0; n < dict.size(); n++) {
		if (beginsWith(dict[n], S)) {
			if (find(S.substr(dict[n].size()), dict) == 1) return 1;
		}
	}

	return 0;
}

int main() {

	int T, N;
	string S;
	vector<string> dict;

	cin >> T;

	while (T--) {
		cin >> N;
		for (int n = 0; n < N; n++) {
			string word;
			cin >> word;
			dict.push_back(word);
		}
		cin >> S;
		cout << find(S, dict) << endl;
	}

	return 0;
}