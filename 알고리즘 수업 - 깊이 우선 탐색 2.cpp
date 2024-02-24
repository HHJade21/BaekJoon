#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, r, a, b, cnt = 2;
vector<int> g[100001];
vector<int> c(100001, 0);
vector<bool> visited(100001, 0);

bool comp(int a, int b){
    return a > b;
}

void dfs(int now){
    int size = g[now].size();
    for(int i = 0; i < size; i++){
        int next = g[now][i];
        if(!visited[next]){
            visited[next] = true;
            c[next] = cnt++;
            dfs(g[now][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        sort(g[i].begin(), g[i].end(), comp);
    }

    c[r] = 1;
    visited[r] = true;
    dfs(r);

    for(int i = 1; i <= n; i++){
        cout << c[i] << "\n";
    }
}