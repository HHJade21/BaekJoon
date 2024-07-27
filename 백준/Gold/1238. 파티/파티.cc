#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, m, strt, s, e, w,ans=0;
struct node{
    int v;
    int w;
};
struct cmp{
    bool operator()(node a, node b){
        return a.w>b.w;
    }
};
vector<node>g[1001];
vector<node>rg[1001];
vector<int>dist(1001, INT_MAX);
vector<int>rdist(1001,INT_MAX);
vector<bool>visit(1001,false);
priority_queue<node, vector<node>,cmp>q;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> strt;

    for(int i = 0; i < m; i++){
        cin >> s >> e >> w;
        g[s].push_back({e,w});
        rg[e].push_back({s, w});
    }

    dist[strt]=0;
    q.push({strt,0});

    while(q.size()){
        int now = q.top().v;
        q.pop();
        if(visit[now])continue;
        visit[now]=true;
        for(auto i : g[now]){
            if(dist[i.v]>dist[now]+i.w){
                dist[i.v]=dist[now]+i.w;
                q.push({i.v, dist[i.v]});
            }
        }
    }

    visit=vector<bool>(n+1,false);

    q.push({strt, 0});
    rdist[strt]=0;
    while(q.size()){
        int now = q.top().v;
        q.pop();
        if(visit[now])continue;
        visit[now]=true;
        for(auto i : rg[now]){
            if(rdist[i.v]>rdist[now]+i.w){
                rdist[i.v]=rdist[now]+i.w;
                q.push({i.v, rdist[i.v]});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        ans = max(ans, dist[i]+rdist[i]);
    }



    cout << ans;
}