#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,color,ans1=0,ans2=0, dy[4]={-1,1,0,0},dx[4]={0,0,-1,1};
int map[100][100], map2[100][100];//적록x 버전 지도, 적록색약 버전 지도
queue<pair<int,int>>q;//bfs진행할 큐
vector<vector<bool>>vis;//방문표시

void bfs1(){//적록x버전 지도에서 color와 같은 색상을 찾아 탐색
    while(q.size()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y+dy[i], nx = x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=n)continue;//맵 범위 체크
            if(vis[ny][nx])continue;//방문여부 체크
            if(map[ny][nx]!=color)continue;//같은 색상 아닌 경우도 건너뛰기
            vis[ny][nx]=true;
            q.push({ny,nx});
        }
    }
}

void bfs2(){//적록색약 버전 지도에서 color와 같은 색상을 찾아 탐색
    while(q.size()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y+dy[i], nx = x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=n)continue;//맵 범위 체크
            if(vis[ny][nx])continue;//방문여부 체크
            if(map2[ny][nx]!=color)continue;//같은 색상 아닌 경우도 건너뛰기
            vis[ny][nx]=true;
            q.push({ny,nx});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin>>n;
    for(int i = 0; i<  n; i++){//n줄에 걸쳐 지도 정보 입력
        cin>>s;
        for(int j = 0; j < n; j++){//한 줄 문자열을 0(빨)1(초)2(파)로 맵에 표시
            if(s[j]=='R'){//빨간색은 배열에 0으로 표시
                map[i][j]=0;
                map2[i][j]=0;
            }
            else if(s[j]=='G'){//초록색은 1. 근데 적록색약버전에서는 0
                map[i][j]=1;
                map2[i][j]=0;//적록색약 버전 지도는 다 빨간색으로 통일
            }
            else{//파란색은 2
                map[i][j]=2;
                map2[i][j]=2;
            }
        }
    }
    
    vis = vector<vector<bool>>(n,vector<bool>(n,0));//방문배열 초기화
    for(int i = 0; i < n;i++){//일단 적록색약 아닌 버전으로 bfs
        for(int j = 0; j < n; j++){//맵의 모든 좌표를 탐색해서
            if(!vis[i][j]){//아직 방문 안 했으면
                color=map[i][j];//탐색할 색깔을 현재 좌표 색상으로 맞춰주고
                q.push({i,j});
                vis[i][j]=true;
                bfs1();
                ans1++;//적록x버전 영역수 카운트
            }
        }
    }

    vis = vector<vector<bool>>(n,vector<bool>(n,0));//방문배열 초기화
    for(int i = 0; i < n;i++){//적록색약 버전으로 bfs
        for(int j = 0; j < n; j++){//맵의 모든 좌표를 탐색해서
            if(!vis[i][j]){//아직 방문 안 했으면
                color=map2[i][j];//탐색할 색깔을 현재 좌표 색상으로 맞춰주고
                q.push({i,j});
                vis[i][j]=true;
                bfs2();
                ans2++;//적록x버전 영역수 카운트
            }
        }
    }

    cout << ans1 << " " << ans2;
}