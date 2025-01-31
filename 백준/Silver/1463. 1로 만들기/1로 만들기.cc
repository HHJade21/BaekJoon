#include<iostream>
#include<vector>
using namespace std;
vector<int>dp(3000001,0);

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        if(dp[2*i]==0 || dp[2*i]>dp[i]+1)dp[2*i]=dp[i]+1;
        if(dp[3*i]==0 || dp[3*i]>dp[i]+1)dp[3*i]=dp[i]+1;
        if(dp[i+1]==0 || dp[i+1]>dp[i]+1)dp[i+1]=dp[i]+1;
    }
    cout << dp[n];
}