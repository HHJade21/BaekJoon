#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;

    vector<int>stair(n, 0);
    vector<int>dp(n,0);

    for(int i = 0; i < n; i++)cin>>stair[i];

    if(n==1)
    {
        cout << stair[0];
        return 0;
    }
    else if(n==2)
    {
        cout << stair[0]+stair[1];
        return 0;
    }

    dp[0] = stair[0];
    dp[1] = stair[0]+stair[1];
    dp[2] = max(stair[0]+stair[2], stair[1]+stair[2]);

    for(int i = 3; i < n; i++)
    {
        dp[i]= max(dp[i-3]+stair[i-1]+stair[i], dp[i-2]+stair[i]);
    }

    cout << dp[n-1];
}