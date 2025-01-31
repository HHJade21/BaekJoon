#include<iostream>
#include<vector> 
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, max;
	cin >> n;
	vector<int>value(n + 1, 0);
	vector<int>maxPrice(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> value[i];
		maxPrice[i] = value[i];
		max = 0;
		for (int j = 0; j <= i / 2; j++) {
			max = maxPrice[i - j] + maxPrice[j] > max ? maxPrice[i - j] + maxPrice[j] : max;
		}
		maxPrice[i] = max;
	}

	cout << maxPrice[n];
}