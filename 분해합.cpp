#include<iostream>
using namespace std;
int main() {
	int N, j, sum = 0;
	cin >> N;
	if (N == 1) {
		cout << '0';
		return 0;
	}

	for (int i = 1; i < N; i++) {
		sum = 0;
		j = i;
		sum += i;

		while (1) {
			sum += j % 10;
			j /= 10;
			if (j == 0)
				break;
		}
		if (sum == N) {
			cout << i;
			break;
		}
		if (i == N - 1) {
			cout << '0';
		}
	}
}