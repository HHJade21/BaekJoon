#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,m,a,b;
vector<int>child[100001];
int dp[100001]={0,};

void dfs(int now){
    for(auto i : child[now]){
        dp[i]+=dp[now];
        dfs(i);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    cin>>a;
    for(int i = 2; i <= n; i++){
        cin>>a;
        child[a].push_back(i);
    }

    for(int i = 0; i < m; i++){
        cin>>a>>b;
        dp[a]+=b;
    }

    dfs(1);

    for(int i = 1; i <=n; i++)cout << dp[i] << " ";
}