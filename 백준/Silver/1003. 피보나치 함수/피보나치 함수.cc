#include<iostream>
using namespace std;

int main() {
	int T, N;
	cin >> T;

	int a[41];
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i < 41; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}



	for (int i = 0; i < T; i++) {
		cin >> N;
		if (N == 0)
			cout << "1 0\n";
		else
			cout << a[N - 1] << " " << a[N] << "\n";
	}

}