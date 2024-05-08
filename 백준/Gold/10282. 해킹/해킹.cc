#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int t,n,m,strt,s,e,w,cnt,time;
struct node{
    int v;
    int w;
};
struct cmp{
    bool operator()(node a, node b){
        return a.w>b.w;
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cnt=0;
        time=0;
        cin >> n >> m >> strt;
        vector<vector<node>>g(n+1);
        vector<bool>visit(n+1,false);
        priority_queue<node, vector<node>, cmp>q;
        vector<int>dist(n+1,INT_MAX);
        for(int i = 0; i < m; i++){
            cin >> e >> s >> w;
            g[s].push_back({e,w});
        }

        dist[strt]=0;
        q.push({strt,0});

        while(q.size()){
            int now = q.top().v;
            q.pop();
            if(visit[now])continue;
            time=max(time, dist[now]);
            cnt++;
            visit[now]=true;
            for(auto i : g[now]){
                if(dist[i.v]>dist[now]+i.w){
                    dist[i.v]=dist[now]+i.w;
                    q.push({i.v, dist[i.v]});
                }
            }
        }

        cout << cnt << " " << time << "\n";
    }
}