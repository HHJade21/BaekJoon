#include <iostream>
using namespace std;
int n, k,w[101],v[101];
int dp[101][1000001] = {};
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i] ;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else
			    dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
		}
	}
	cout << dp[n][k];
}