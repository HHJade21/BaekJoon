#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int p[100001], chk[100001],n,m,u,v,ans;

int find(int x){
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
}

void unioon(int x, int y){
    x = find(x),y=find(y);
    p[x]=y;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i = 1; i <=n; i++)p[i]=i;
    for(int i =  0 ; i < m; i++){
        cin>>u>>v;
        if(find(u)==find(v))ans++;
        else unioon(u,v);
    }
    for(int i = 1; i <=n; i++){
        int v = find(i);
        if(!chk[v]){
            ans++;
            chk[v]=1;
        }
    }
    cout<<ans-1;
}