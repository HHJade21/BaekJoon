#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, map[100][100] = {0,}, cnt = 1, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
bool visited[100][100] = {0,};
queue<pair<int, int>> bfsQ;

void bfs(){
    int size, nowy, nowx, newy, newx;
    while(!bfsQ.empty()){
        size = bfsQ.size();
        cnt++;
        for(int i = 0; i < size; i++){
            nowy = bfsQ.front().first;
            nowx = bfsQ.front().second;
            for(int j = 0; j < 4; j++){
                newy = nowy + dy[j];
                newx = nowx + dx[j];
                if(newy >= 0 && nowy < n && newx >= 0 && newx < m && map[newy][newx] && !visited[newy][newx]){
                    if(newy == n-1 && newx == m-1){
                        return;
                    }
                    visited[newy][newx] = true;
                    bfsQ.push({newy, newx});
                }
            }
            bfsQ.pop();
        }
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '1') map[i][j] = 1;
        }
    }
    bfsQ.push({0,0});
    visited[0][0]=true;

    bfs();

    cout << cnt;
}