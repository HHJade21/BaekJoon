#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n, del,tmp, r,ans=0;
bool vis[50]={};
vector<int>g[50];


void dfs(int now){
    vis[now]=true;
    int child=0;
    for(auto i : g[now]){
        if(i==del)continue;

        child++;
        dfs(i);
    }
    if(!child)ans++;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>tmp;
        if(tmp==-1){
            r=i;
            continue;
        }
        g[tmp].push_back(i);
    }
    cin>>del;

    if(del!=r)dfs(r);
    cout<<ans;
}