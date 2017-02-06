#include <iostream>
#include <stack>
using namespace std;

int main() {

	int T;
	cin >> T;

	while (T--) {
		string in;
		int c, prev, best;
		stack<int> levelMin;
		stack<int> levelValue;

		c = prev = best = 0;

		cin >> in;

		for (size_t i = 0; i < in.size(); i++) {
			if (in[i] == '(') {
				if ((i == 0 || in[i-1] == ')')) {
					levelMin.push(c);
					levelValue.push(prev);
					prev = 0;
				}
				c++;
			}
			else if (in[i] == ')') {
				if (c > 0) {
					c--;
					if (levelMin.top() == c) {
						levelMin.pop();
						prev += levelValue.top();
						levelValue.pop();
					}
					prev++;
					best = max(best, prev);
				}
				else if (i > 0 && in[i-1] == ')') {
					prev = 0;
				}
			}
		}

		cout << best*2 << endl;
	}

	return 0;
}