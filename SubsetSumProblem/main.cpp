#include <iostream>
using namespace std;

class EqualSumSubset {
private:
	int N;
	int sum;
	int * arr;
	bool ** cache;
public:
	EqualSumSubset(int * a, int n, int s) : N(n), sum(s), arr(a) {
		cache = new bool*[sum+1];
		for (int i = 0; i < sum+1; i++) {
			cache[i] = new bool[N+1];
		}
	}

	~EqualSumSubset() {
		for (int i = 0; i < sum+1; i++) {
			delete [] cache[i];
		}
		delete [] cache;
	}

	bool isSumOf() {
		// check if we can split the sum into two integer sums
		if (sum % 2 != 0) return false;

		// decomposition by sum of subset, iterative DP
		for (int s = 0; s < sum+1; s++) {
			for (int n = 0; n < N+1; n++) {
				if (s == 0) 
					cache[s][n] = true;
				else if (n == 0) 
					cache[s][n] = false;
				else {
					cache[s][n] = cache[s][n-1];
					if (s >= arr[n-1]) {
						cache[s][n] = cache[s][n] || cache[s - arr[n-1]][n-1];
					}
				}
				if (s == sum/2 && cache[s][n]) return true;
			}
		}

		return false;
	}

};

int main() {

	int T;
	cin >> T;

	while (T--) {
		int N, sum;
		int* arr;

		cin >> N;

		arr = new int[N];
		sum = 0;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		EqualSumSubset inst(arr, N, sum);

		cout << (inst.isSumOf() ? "YES" : "NO") << endl;

		delete [] arr;
	}

	return 0;
}