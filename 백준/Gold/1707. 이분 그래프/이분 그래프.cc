#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int>> g;
vector<bool> visit;
vector<int> color;
int t, v, e, a, b;
bool bi = true;

void dfs(int now){
    for(int i : g[now]){
        if(!bi) return;

        if(!visit[i]){
            color[i] = (color[now]+1)%2;
            visit[i]=true;
            dfs(i);
        }
        else if(color[i] == color[now]){
            bi = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> v >> e;
        g=vector<vector<int>>(v+1, vector<int>());
        visit=vector<bool>(v+1,0);
        color=vector<int>(v+1,0);
        bi = true;

        for(int j = 0; j < e; j++){
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        for(int j = 1; j <= v; j++){
            if(!bi) break;
            dfs(j);
        }

        if(bi) cout << "YES\n";
        else cout << "NO\n";
    }
}