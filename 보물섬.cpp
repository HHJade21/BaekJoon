#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
vector<string> map;
int r, c;
struct node{
    int y;
    int x;
};
queue<node> bfsQ;
int bfs(vector<vector<bool>> visit, int a, int b){
    bfsQ.push({a, b});
    visit[a][b] = true;
    int size, nowy, nowx, newy, newx, count = 0;
    bool way = false;
    while(!bfsQ.empty()){
        size = bfsQ.size();
        way = false;
        for(int i = 0; i < size; i++){
            nowy = bfsQ.front().y;
            nowx = bfsQ.front().x;
            for(int j = 0; j < 4; j++){
                newy = nowy + dy[j];
                newx = nowx + dx[j];

                if(newy >= 0 && newx >= 0 && newy < r && newx < c && map[newy][newx] == 'L' && !visit[newy][newx]){
                    visit[newy][newx] = true;
                    bfsQ.push({newy, newx});
                    way = true;
                }
            }
            bfsQ.pop();
        }
        if(way){
            count++;
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    int max = 0, temp;
    cin >> r >> c;
    vector<vector<bool>> visit(r, vector<bool>(c, 0));
    for(int i = 0; i < r; i++){
        cin >> s;
        map.push_back(s);
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(map[i][j] == 'L'){
                temp = bfs(visit, i, j);
                max = max >= temp ? max : temp;
            }
        }
    }
    cout << max;
    
}