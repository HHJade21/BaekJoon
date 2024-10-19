#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, v, dest,weight, ans = 0, secondNode;
struct edge{
    int d;
    int w;
};
vector<vector<edge>> g;
vector<bool> vis;

void dfs(int a, int depth){
    bool next=false;

    for(int i = 0; i < g[a].size(); i++){
        if(vis[g[a][i].d])continue;

        next = true;
        vis[g[a][i].d] = true;
        dfs(g[a][i].d, depth+g[a][i].w);
    }

    if(!next && ans < depth){
        ans = depth;
        secondNode = a;
    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;

    g = vector<vector<edge>>(n+1, vector<edge>());
    vis = vector<bool>(n, 0);
    for(int k = 0; k < n; k++){
        cin >> v >> dest;
        while(dest!=-1){
            cin >> weight;
            g[v].push_back({dest, weight});
            g[dest].push_back({v, weight});
            cin>>dest;
        }
    }
    

    vis[1]=true;
    dfs(1, 0);
    vis = vector<bool>(n, 0);
    vis[secondNode] = true;
    dfs(secondNode, 0);

    cout << ans;
}