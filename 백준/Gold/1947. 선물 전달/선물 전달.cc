#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, mod = 1000000000;
    cin >> n;

    vector<long long>dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i = 3; i <= n; i++){
        dp[i] = (i-1)*((dp[i-1]+dp[i-2])%mod)%mod;
    }
    cout << dp[n];
}
