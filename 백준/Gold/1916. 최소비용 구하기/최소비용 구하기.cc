#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

struct node{
    int v;
    int w;
};

struct cmp{
    bool operator()(node a, node b){
        return a.w>b.w;
    }
};

int n, m,a,b,s,e,w,sp,ep;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;

    vector<node>g[n+1];
    bool visited[n+1]={0,};
    priority_queue<node, vector<node>,cmp>pq;
    vector<int>dist(n+1,INT_MAX);

    while(m--){
        cin>>s>>e>>w;
        g[s].push_back({e,w});
    }

    cin>>sp;
    pq.push({sp,0});
    dist[sp]=0;
    
    while(!pq.empty()){
        int now = pq.top().v;
        pq.pop();
        if(visited[now])continue;
        visited[now]=true;
        for(auto i : g[now]){
            if(dist[i.v]>dist[now]+i.w){
                dist[i.v]=dist[now]+i.w;
                pq.push({i.v, dist[i.v]});
            }
        }
    }
    cin>>ep;
    cout<<dist[ep];

}