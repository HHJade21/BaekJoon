#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

vector<int>g[100001];
int depth[100001];
int s,d,n,x,y,ans;

int dfs(int now, int bef){
    for(auto i : g[now]){
        if(i!=bef)
            depth[now]=max(depth[now],dfs(i,now)+1);
    }
    if(depth[now]>=d && now!=s)ans++;
    return depth[now];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>s>>d;
    for(int i = 1; i < n; i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(s,-1);
    cout<<ans*2;
}