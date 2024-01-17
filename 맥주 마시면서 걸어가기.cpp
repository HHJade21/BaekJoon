#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int, int>> p;
vector<bool> visit;
pair<int, int> home;
pair<int, int> rock;
int cnt = 0, n, clear = 0, dest;
bool move(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second) <= 1000;
}

void dfs(int a){
    if(clear == 1){
        return;
    }
    else if(a == dest){
        clear = 1;
        return;
    }
    for(int i = 1; i <= dest; i++){
        if(clear == 1)
            return;
        if(!visit[i] && move(p[a], p[i])){
            visit[i] = true;
            dfs(i);
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        clear = 0;
        cin >> n;
        dest = n+1;
        p = vector<pair<int, int>>(n+2);
        visit = vector<bool>(n+2);
        cin >> p[0].first >> p[0].second;
        for(int j = 1; j <= n; j++){
            cin >> p[j].first >> p[j].second;
        }
        cin >> p[dest].first >> p[dest].second;
        visit[0] = true;
        dfs(0);
        if(clear){
            cout << "happy\n";
        }
        else{
            cout << "sad\n";
        }
    }
}