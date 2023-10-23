#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    int y;
    int x;
};
int n, danjisoo = 0;
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};
vector<vector<int>> map(25, vector<int>(25, 0));
vector<vector<bool>> visit(25, vector<bool>(25, 0));
queue<node> bfsQ;
vector<int> danji;

void bfs(){
    int size, nowy, nowx, newy, newx, dcount = 1;
    while(!bfsQ.empty()){
        size = bfsQ.size();
        for(int i = 0; i < size; i++){
            nowy = bfsQ.front().y;
            nowx = bfsQ.front().x;
            for(int j = 0; j < 4; j++){
                newy = nowy + dy[j];
                newx = nowx + dx[j];
                if(newy >= 0 && newx >= 0 && newy < n && newx < n && map[newy][newx] && !visit[newy][newx]){
                    visit[newy][newx] = true;
                    bfsQ.push({newy, newx});
                    dcount++;
                }
            }
            bfsQ.pop();
        }
    }
    danji.push_back(dcount);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> n;

    
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '1'){
                map[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1 && !visit[i][j]){
                danjisoo++;
                visit[i][j] = true;
                bfsQ.push({i, j});
                bfs();
            }
        }
    }
    cout << danjisoo << "\n";
    sort(danji.begin(), danji.end());
    for(auto i : danji){
        cout << i << "\n";
    }
}