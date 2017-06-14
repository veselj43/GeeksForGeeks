#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int T, N, k;

	cin >> T;

	while (T--) {
		cin >> N;

		int* a = new int[N];

		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}

		cin >> k;

		vector<int> diff;

		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				diff.push_back(abs(a[i] - a[j]));
			}
		}

		sort(diff.begin(), diff.end());

		cout << diff[k-1] << endl;

	}

	return 0;
}