#include<iostream>
#include<vector>
using namespace std;


int main() {
	int n, m, start, end, ball;

	cin >> n >> m;
	vector<int> basket(n, 0);
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> ball;

		for (int j = start - 1; j < end; j++) {
			basket[j] = ball;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << basket[i] << " ";
	}


	return 0;
}