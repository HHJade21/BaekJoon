#include<iostream>
#include<vector>
using namespace std;

vector<int> g[100001];
bool vis[100001];
vector<int>dp(100001,1);
int n,r,q,u,v;

int dfs(int now){
    vis[now]=1;
    for(auto i : g[now]){
        if(vis[i])continue;
        dp[now]+=dfs(i);
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
        cin>>u;
        cout<<dp[u]<<"\n";
    }
}