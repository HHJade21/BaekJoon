#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

queue<int> bfsQ;
vector<int> g[10001];
vector<bool> visit;
vector<int> hack(10001, 0);
int n, m, v, u, cnt, large;


void bfs(int now){
    bfsQ.push(now);
    visit[now]=true;

    while(!bfsQ.empty()){
        int qsize=bfsQ.size();
        for(int i = 0; i < qsize; i++){
            int x = bfsQ.front();
            bfsQ.pop();
            int size = g[x].size();
            for(int j = 0; j < size; j++){
                int next = g[x][j];
                if(!visit[next]){
                    hack[now]++;
                    visit[next]=true;
                    bfsQ.push(next);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> v >> u;
        g[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){
        if(!g[i].empty()){
            visit=vector<bool>(n+1, 0);
            bfs(i);
            if(hack[i] > large) large = hack[i];
        }
    }

    for(int i = 1; i <= n; i++){
        if(hack[i]==large) {
            cout << i << " ";
        }
    }
}