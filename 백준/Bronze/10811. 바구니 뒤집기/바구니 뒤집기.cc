#include<iostream>
#include<vector>
using namespace std;


int main() {
	int n, m, start, end, range, temp;

	cin >> n >> m;

	vector<int> basket(n);
	vector<int> copy(n);
	for (int i = 0; i < n; i++) {
		basket[i] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		range = end - start;
		range /= 2;
		range++;
		for (int j = 0; j < range; j++) {
			temp = basket[start - 1 + j];
			basket[start - 1 + j] = basket[end - 1 - j];
			basket[end - 1 - j] = temp;
		}
	}


	for (int i = 0; i < n; i++) {
		cout << basket[i] << " ";
	}
	return 0;
}