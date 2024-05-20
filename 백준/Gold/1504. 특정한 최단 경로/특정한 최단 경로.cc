#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
//다익스트라 최소 2회, 최대 4회 해야됨.
//v1==1이거나 v2==n이면 3회, 둘다면 2회.
struct node{
    int v;
    int w;
};
struct cmp{
    bool operator()(node a, node b){
        return a.w>b.w;
    }
};
priority_queue<node, vector<node>,cmp>q;


vector<node>g[801];
int n, m,s,e,w,v1,v2,d1v1, d1v2, d1n, dv1v2, dv1n, dv2n;

vector<int>dist(801,INT_MAX);
vector<bool>visited(801,false);

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin >> s >> e >> w;
        g[s].push_back({e,w});
        g[e].push_back({s,w});
    }
    cin>>v1>>v2;

    //1번에서 시작하는 다익스트라로 dist(1~v1),dist(1~v2),dist(1~n)구하기
    dist[1]=0;
    q.push({1,0});

    while(!q.empty()){
        int now = q.top().v;
        q.pop();
        if(visited[now])continue;
        visited[now]=true;
        for(auto i : g[now]){
            if(dist[i.v]>dist[now]+i.w){
                dist[i.v]=dist[now]+i.w;
                q.push({i.v, dist[i.v]});
            }
        }
    }
    d1v1=dist[v1], d1v2=dist[v2], d1n=dist[n];
    if(dist[v1]==INT_MAX||dist[v2]==INT_MAX||dist[n]==INT_MAX){
        cout<<-1;
        return 0;
    }

    //v1!=1일 때, v1에서 시작하는 다익스트라로 dist(v1~v2),dist(v1~n)구하기
    if(v1==1){
        dv1v2=d1v2, dv1n=d1n;
    }
    else{
        dist=vector<int>(801,300000000);
        visited=vector<bool>(801,false);
        dist[v1]=0;
        q.push({v1,0});
        while(!q.empty()){
            int now = q.top().v;
            q.pop();
            if(visited[now])continue;
            visited[now]=true;
            for(auto i : g[now]){
                if(dist[i.v]>dist[now]+i.w){
                    dist[i.v]=dist[now]+i.w;
                    q.push({i.v,dist[i.v]});
                }
            }
        }
        dv1v2=dist[v2], dv1n=dist[n];
    }
    //v2!=n일 때, v2에서 시작하는 다익스트라로 dist(v2~n)구하기
    if(v2==n){
        dv2n=0;
    }
    else{
        dist=vector<int>(801,INT_MAX);
        visited=vector<bool>(801,false);
        dist[v2]=0;
        q.push({v2,0});
        while(!q.empty()){
            int now = q.top().v;
            q.pop();
            if(visited[now])continue;
            visited[now]=true;
            for(auto i : g[now]){
                if(dist[i.v]>dist[now]+i.w){
                    dist[i.v]=dist[now]+i.w;
                    q.push({i.v,dist[i.v]});
                }
            }
        }
        dv2n=dist[n];
    }

    int ans = min(d1v1+dv1v2+dv2n, d1v2+dv1v2+dv1n);
    cout << ans;
}