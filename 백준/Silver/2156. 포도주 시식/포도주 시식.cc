#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,tmp,ans=0;
    cin >> n;
    vector<int>podo(n+1,0);
    vector<int>dp(n+1,0);
    for(int i  = 1 ; i <= n; i++){
        cin>>podo[i];
    }
    dp[1]=podo[1];
    ans=podo[1];
    if(n>1){
        dp[2]=dp[1]+podo[2];
        if(dp[2]>ans)ans=dp[2];
    }
    if(n>2){
        dp[3]=max(podo[2]+podo[3],podo[1]+podo[3]);
        if(dp[3]>ans)ans=dp[3];
    }

    

    for(int i = 4; i <= n; i++){
        dp[i] = max(max(dp[i-2]+podo[i], dp[i-3]+podo[i-1]+podo[i]), dp[i-4]+podo[i-1]+podo[i]);
        if(dp[i]>ans)ans=dp[i];
    }

    cout << ans;
}