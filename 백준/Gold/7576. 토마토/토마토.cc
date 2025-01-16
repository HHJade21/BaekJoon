#include <bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;
int box[1000][1000]={0,};
int dy[4]={-1,1,0,0},dx[4]={0,0,-1,1}, cnt = -1, tt=0,n,m;

void bfs(){
    while(q.size()){
        int size=q.size();
        cnt++;
        for(int i = 0; i < size;i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int j = 0; j < 4; j++){
                int ny = y+dy[j], nx = x+dx[j];
                if(ny<0||ny>=n||nx<0||nx>=m)continue;
                if(box[ny][nx])continue;

                q.push({ny,nx});
                box[ny][nx]=1;
                tt--;
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> box[i][j];
            if(box[i][j]==1){
                q.push({i,j});
            }
            else if(box[i][j]==0){
                tt++;
            }
        }
    }
    bfs();

    if(tt>0) cout << "-1";
    else cout << cnt;
}
