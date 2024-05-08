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
    bool operator()(node a,node b){
        return a.w>b.w;
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, k, s, e, w;

    cin >> n >> m >> k;
    vector<node>g[n+1];
    priority_queue<int,vector<int>,less<int>>dist[n+1];//w클수록 top
    priority_queue<node,vector<node>,cmp>pq;
    vector<int>visited(n+1,0);
    while(m--){
        cin>>s>>e>>w;
        g[s].push_back({e,w});
    }
    dist[1].push(0);
    pq.push({1,0});


    while(!pq.empty()){
        int now = pq.top().v;
        int nowDist = pq.top().w;
        pq.pop();
        for(auto i : g[now]){
            int nextDist = nowDist+i.w;
            if(dist[i.v].size()<k){//dist size가 k미만이면 그냥 push
                dist[i.v].push(nextDist);
                pq.push({i.v, nextDist});
            }
            else if(dist[i.v].top() > nextDist){//이상이면 top보다 작으면 빼고 push
                dist[i.v].pop();
                dist[i.v].push(nextDist);
                pq.push({i.v, nextDist});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(dist[i].size()<k) cout << -1 << "\n";
        else cout << dist[i].top() << "\n";
    }


}