#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, m, strt, dest, a, b, w;



struct node{
    int v;
    int w;
};

struct cmp{
    bool operator()(node a, node b){
        return a.w>b.w;
    }
};

priority_queue<node, vector<node>, cmp>pq;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m >> strt;

    vector<node>g[n+1];
    bool visited[n+1]={0,};
    while(m--){
        cin >> a >> b >> w;
        g[a].push_back({b,w});
    }

    vector<int>dist(n+1, INT_MAX);
    dist[strt]=0;

    pq.push({strt,0});


    while(!pq.empty()){
        int now = pq.top().v;
        pq.pop();
        if(visited[now])continue;
        visited[now]=true;
        for(auto i : g[now]){
            if(dist[i.v] > dist[now]+i.w){
                dist[i.v]=dist[now]+i.w;
                pq.push({i.v, dist[i.v]});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(dist[i]==INT_MAX) cout << "INF\n";
        else cout << dist[i]<<"\n";
    }
}