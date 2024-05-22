#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
//다익스트라 풀이
// struct node{
//     int v;
//     int w;
// };
// struct cmp{
//     bool operator()(node a, node b){
//         return a.w>b.w; 
//     }
// };
// vector<node>g[1001];
// priority_queue<node,vector<node>,cmp>q;

// int main(){
//     ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//     int n, m, s, e, w;

//     cin >> n >> m;

//     for(int i = 1; i < n; i++){
//         cin >> s >> e >> w;
//         g[s].push_back({e,w});
//         g[e].push_back({s,w});
//     }


//     while(m--){
//         cin >> s >> e;
//         vector<bool>visited(1001,0);
//         vector<int>dist(1001,INT_MAX);
//         dist[s]=0;
//         q.push({s,0});

//         while(!q.empty()){
//             int now = q.top().v;
//             q.pop();
//             if(visited[now])continue;
//             visited[now]=true;
//             for(auto i : g[now]){
//                 if(dist[i.v]>dist[now]+i.w){
//                     dist[i.v]=dist[now]+i.w;    
//                     q.push({i.v, dist[i.v]});
//                 }
//             }
//         }

//         cout << dist[e] << "\n";
//     }

// }


//dfs풀이

struct node{
    int v;
    int w;
};
vector<node>g[10001];
vector<bool>visited(10001,0);
int n, m, dist=0, s, e, w;

void dfs(int now){
    if(now==e){
        cout << dist << "\n";
        return;
    }
    for(auto i : g[now]){
        if(!visited[i.v]){
            visited[i.v]=true;
            dist+=i.w;
            dfs(i.v);
            dist-=i.w;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i<n; i++){
        cin>>s>>e>>w;
        g[s].push_back({e,w});
        g[e].push_back({s,w});
    }

    while(m--){
        dist=0;
        visited=vector<bool>(10001,0);
        cin >> s >> e;
        visited[s]=true;
        dfs(s);
    }

}