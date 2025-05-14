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
vector<node>g[50001];
priority_queue<node, vector<node>,cmp>q;
vector<int>dist(50001, INT_MAX);
vector<bool>visited(50001,0);

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, s, e, w, ans=0;

    cin >> n >> m;

    while(m--){
        cin >> s >> e >> w;
        g[s].push_back({e,w});
        g[e].push_back({s,w});
    }

    dist[1]=0;
    q.push({1,0});

    while(!q.empty()){
        int now = q.top().v;
        q.pop();
        if(visited[now])continue;
        visited[now]=true;
        for(auto i:g[now]){
            if(dist[i.v]>dist[now]+i.w){
                dist[i.v]=dist[now]+i.w;
                q.push({i.v, dist[i.v]});
            }
        }
    }

    cout << dist[n];
}