#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int t, n, m, k, a, b, ji=0, dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1};
bool map[50][50], visit[50][50];


void dfs(int y, int x){
    visit[y][x]=true;
    for(int i = 0; i < 4; i++){
        int newy = y + dy[i], newx = x + dx[i];
        if(newy<0 || newx < 0 || newy >=n || newx >= m)continue;

        if(map[newy][newx] == 1 && !visit[newy][newx]){
            dfs(newy, newx);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;

    while(t--){
        ji=0;
        cin >> m >> n >> k;
        for(int i = 0; i < n; i++){//밭 초기화
            for(int j = 0; j < m; j++){
                map[i][j]=0;
                visit[i][j]=0;
            }
        }

        for(int i = 0; i < k; i++){//배추 심기
            cin >> b >> a;
            map[a][b]=1;
        }

        for(int i = 0; i < n; i++){//밭의 모든 칸에 대해서
            for(int j = 0; j < m; j++){
                if(map[i][j] && !visit[i][j]){
                    dfs(i, j);
                    ji++;
                }
            }
        }
        cout<< ji << "\n";
    }
}
