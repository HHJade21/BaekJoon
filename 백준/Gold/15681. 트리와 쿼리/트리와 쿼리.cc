#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,r,q,u,v;
int tsize[100001];
vector<int>g[100001];
vector<int>child[100001];
int vis[100001]={0,};

void dfs(int now){
    vis[now]=true;
    for(auto i : g[now]){
        if(vis[i])continue;
        child[now].push_back(i);
        dfs(i);
    }
}

int countChild(int now){
    tsize[now]=1;
    for(auto i : child[now]){
        tsize[now]+=countChild(i);
    }
    return tsize[now];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>r>>q;

    for(int i = 1; i < n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(r);
    countChild(r);

    for(int i = 0; i < q; i++){
        cin>>v;
        cout << tsize[v] << "\n";
    }    
}