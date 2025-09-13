#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

vector<int>g[100001];
int depth[100001];
int s,d,n,x,y,ans=0;

int dfs(int now, int bef){
    int cut=0;
    for(auto i : g[now]){
        if(i!=bef)
            cut=max(cut,dfs(i,now)+1);
    }
    if(cut>=d&&now!=s)ans++;
    return cut;
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