#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;



int main() {
	int n;
	cin >> n;
	vector <int> price(n+1,0);
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> price[i];
		dp[i] = price[i];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i / 2; j++) {
			dp[i] = max(dp[j] + dp[i - j], dp[i]);
		}
	}
	cout << dp[n];
}