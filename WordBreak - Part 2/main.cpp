#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct TNode {
	string part;
	vector<TNode*> next;
	TNode(string s) : part(s) {}
	~TNode() {
		for (size_t i = 0; i < next.size(); i++) {
			delete next[i];
		}
	}
};

bool beginsWith(string s1, string s2) {
	for (size_t i = 0; i < s1.size(); i++) 
		if (s1[i] != s2[i]) return false;
	return true;
}

TNode* find(string S, const vector<string> dict, int n) {
	TNode * node = new TNode((n < 0) ? "" : dict[n]);
	
	if (S.empty()) return node;

	for (size_t n = 0; n < dict.size(); n++) {
		if (beginsWith(dict[n], S)) {
			TNode * add = find(S.substr(dict[n].size()), dict, n);
			if (add != NULL) node->next.push_back(add);
		}
	}

	if (node->next.size() == 0) {
		delete node;
		return NULL;
	}

	return node;
}

void printResult(TNode* node, string prefix) {
	if (!prefix.empty() && !node->part.empty()) prefix += " ";
	prefix += node->part;

	if (node->next.size() == 0) {
		cout << "(" << prefix << ")";
		return;
	}

	for (size_t i = 0; i < node->next.size(); i++) {
		printResult(node->next[i], prefix);
	}
}

void cleanUp(TNode* node) {
	if (node == NULL) return;
	for (size_t i = 0; i < node->next.size(); i++) {
		cleanUp(node->next[i]);
	}
	delete node;
}

int main() {

	int T, N;
	string S;
	vector<string> dict;
	TNode* result;

	cin >> T;

	while (T--) {
		cin >> N;
		for (int n = 0; n < N; n++) {
			string word;
			cin >> word;
			dict.push_back(word);
		}
		cin >> S;

		result = find(S, dict, -1);

		if (result == NULL) 
			cout << "(Empty)";
		else
			printResult(result, "");

		cout << endl;

		if (result != NULL) delete result;
		dict.clear();
	}

	return 0;
}