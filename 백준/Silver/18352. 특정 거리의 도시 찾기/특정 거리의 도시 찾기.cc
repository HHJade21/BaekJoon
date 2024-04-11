#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> g[300001];
vector<int> visited(300001, 0);
queue<int> bfsQ;
int n, m, k, x, a, b, cnt=0;

void bfs(){
    int qsize, now, size, next;
    while(!bfsQ.empty()){
        qsize = bfsQ.size();
        cnt++;
        for(int i = 0; i < qsize; i++){
            now = bfsQ.front();
            bfsQ.pop();
            size = g[now].size();
            for(int j = 0; j < size; j++){
                next = g[now][j];
                if(!visited[next]){
                    visited[next] = cnt;
                    bfsQ.push(next);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> k >> x;


    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b);
    }

    bfsQ.push(x);
    visited[x] = 999999;

    bfs();

    cnt = 0;
    for(auto i : visited){
        if(i == k) cnt++;
    }

    if(!cnt) cout << -1;
    else{
        for(int i = 1; i <= n; i++){
            if(visited[i] == k) 
            cout << i <<  "\n";
        }
    }
}     