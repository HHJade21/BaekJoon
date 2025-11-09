#include<iostream>
#include<vector>
using namespace std;

int n,r,q,u,v;
vector<int>g[100001];
vector<int>dp(100001,1);
bool vis[100001];

int dfs(int now){
    vis[now]=1;
    for(auto i : g[now]){
        if(vis[i])continue;
        dfs(i);
        dp[now]+=dp[i];
    }
    return dp[now];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>r>>q;
    for(int i = 1; i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(r);
    for(int i = 0; i < q; i++){
        cin>>v;
        cout<<dp[v]<<"\n";
    }
}