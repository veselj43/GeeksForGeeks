#include <iostream>
#include <list>
using namespace std;

struct TrieNode {
	char prefix;
	bool end;
	list<TrieNode*> childs;

	TrieNode(char p) : prefix(p), end(false) {}

	~TrieNode() {
		for (list<TrieNode*>::iterator it = childs.begin(); it != childs.end(); it++)
			delete (*it);
	}

	TrieNode* find(char x) {
		for (list<TrieNode*>::iterator it = childs.begin(); it != childs.end(); it++)
			if ((*it)->prefix == x) return (*it);
		return NULL;
	}
};

void TrieAdd(TrieNode* parent, const string &word, int depth = 0) {
	TrieNode* next;

	if (depth == (int)word.size() - 1) {
		parent->end = true;
		return;
	}

	if ((next = parent->find(word[depth])) == NULL) {
		next = new TrieNode(word[depth]);
		parent->childs.push_back(next);
	}

	TrieAdd(next, word, depth+1);
}

bool TrieFind(TrieNode* parent, const string &word, int depth = 0) {
	TrieNode* next;

	if (depth == (int)word.size() - 1)
		return parent->end;

	if ((next = parent->find(word[depth])) == NULL)
		return false;

	return TrieFind(next, word, depth+1);
}

int main() {

	int T;
	cin >> T;

	while (T--) {
		int N;
		string toFind;
		string* words;
		
		cin >> N;

		words = new string[N];

		for (int i = 0; i < N; i++)
			cin >> words[i];

		cin >> toFind;

		TrieNode* root = new TrieNode(' ');

		for (int i = 0; i < N; i++)
			TrieAdd(root, words[i]);

		delete [] words;

		cout << TrieFind(root, toFind) << endl;

		delete root;
	}

	return 0;
}