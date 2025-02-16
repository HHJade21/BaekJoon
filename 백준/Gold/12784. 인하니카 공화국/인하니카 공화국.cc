#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
struct edge{
    int v;
    int w;
};
vector<edge>g[1001];
vector<int>dp(1001,0);
vector<int>tree(1001,0);
vector<bool> vis(1001,0);
int t,n,m,a,b,c;

void dfs(int now,int weight){
    vis[now]=true;
    int res = 0;
    for(auto i : g[now]){
        if(vis[i.v])continue;
        dfs(i.v, i.w);
        res+=dp[i.v];
    }
    if(res==0)dp[now] = weight;
    else {
        if(now==1)dp[now]=res;
        else dp[now] = min(weight, res);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 1; i <=n; i++)g[i].clear();
        dp=vector<int>(n+1,0);
        tree=vector<int>(n+1,0);
        vis=vector<bool>(n+1,0);
        for(int i = 0; i < m; i++){
            cin>>a>>b>>c;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        dfs(1,0);
        cout << dp[1]<<"\n";
    }
}