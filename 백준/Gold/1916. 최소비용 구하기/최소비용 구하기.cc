#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

struct e{
    int v;
    int w;
};

struct cmp{
    bool operator()(e a, e b){
        return a.w>b.w;
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, a, b,w,strt,dest;
    cin>>n>>m;
    vector<e>g[n+1];
    vector<int>dist(n+1,INT_MAX);
    vector<bool>vis(n+1,0);
    priority_queue<e, vector<e>, cmp> pq;

    for(int i = 0; i < m; i++){
        cin>> a >> b >> w;
        g[a].push_back({b,w});
    }
    cin>>strt>>dest;

    dist[strt]=0;
    pq.push({strt,0});

    while(pq.size()){
        int v = pq.top().v;
        pq.pop();
        if(vis[v])continue;
        vis[v]=true;
        for(auto i : g[v]){
            if(dist[i.v]>dist[v]+i.w){
                dist[i.v]=dist[v]+i.w;
                pq.push({i.v,dist[i.v]});
            }
        }
    }
    cout<<dist[dest];
}