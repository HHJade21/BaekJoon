#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int ans = 0;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

struct p{
    int y;
    int x;
};

struct pp{
    int ry;
    int rx;
    int by;
    int bx;
};

queue<pp> bfsQ;
vector<string> map;
int vis[10][10][10][10]={0,};

p Move(p tmp, int dir, int& cnt){
    int y = tmp.y, x = tmp.x;
    while(map[y+dy[dir]][x+dx[dir]]!='#' && map[y][x]!='O') y+=dy[dir], x+=dx[dir], cnt++;
    return {y,x};
}


void BFS(){
    while(bfsQ.size()){
        ans++;
        int qs = bfsQ.size();
        for(int i = 0; i < qs; i++){
            int nry = bfsQ.front().ry, nrx = bfsQ.front().rx, nby = bfsQ.front().by, nbx = bfsQ.front().bx;
            for(int j = 0; j < 4; j++){
                int rc = 0, bc = 0;
                p newr = Move({nry, nrx}, j, rc);
                p newb = Move({nby, nbx}, j, bc);
                if(map[newb.y][newb.x]=='O')continue;
                if(map[newr.y][newr.x]=='O'){
                    if(ans>10)ans=-1;
                    cout << ans;
                    exit(0);
                }
                if(newb.y==newr.y && newb.x==newr.x){//둘이 결과가 겹치는 경우 위치 수정
                    if(rc>bc){//빨간색이 더 많이 움직였으면 빨간색을 뒤로 한 칸 움직여줘야함.
                        newr.y -= dy[j];
                        newr.x -= dx[j];
                    }
                    else{//검은색이 더 많이 움직였으면 검은색을 뒤로 밀어줘야 함.
                        newb.y -= dy[j];
                        newb.x -= dx[j];
                    }
                }
                if(vis[newr.y][newr.x][newb.y][newb.x])continue; // 이미 탐색한 위치면 넘어가기
                //파란색도 빨간색도 구멍에 빠지지 않았고, 처음 탐색하는 좌표쌍일 경우
                bfsQ.push({newr.y, newr.x, newb.y, newb.x});//큐에 삽입
                vis[newr.y][newr.x][newb.y][newb.x] = true;
            }
            bfsQ.pop();
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n, m, rty, rtx, bty, btx;
    cin >> n >> m;
    map = vector<string>(n);

    for(int i = 0; i < n; i++){
        cin >> map[i];
        for(int j = 0; j < m; j++){
            if(map[i][j]=='R'){
                rty = i;
                rtx = j;
            }
            else if(map[i][j]=='B'){
                bty=i;
                btx=j;
            }
        }
    }

    bfsQ.push({rty,rtx,bty,btx});
    vis[rty][rtx][bty][btx]=true;
    BFS();

    cout << -1;
}