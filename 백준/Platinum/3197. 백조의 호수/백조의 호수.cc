#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int r,c,cnt=0, bcnt=0,dy[4]={-1,1,0,0},dx[4]={0,0,-1,1},ans=0;
vector<vector<bool>> vis;
vector<string>map;
struct pos{
    int y;
    int x;
};
vector<vector<pos>>p;
queue<pos>q;
pos p1,p2;

bool samePos(pos a, pos b){
    return a.y==b.y&&a.x==b.x;
}

pos Find(pos a){
    if(samePos(p[a.y][a.x], a))return a;
    return p[a.y][a.x]=Find(p[a.y][a.x]);
}

void UnionFind(pos a, pos b){
    a = Find(a);
    b = Find(b);

    if(!samePos(a,b)){
        p[a.y][a.x]={b.y,b.x};
    }
}


void dfs(int y, int x){//초기 물 영역 탐색
    if(map[y][x]=='L'){//백조면
        if(bcnt++)p1={y,x};//첫 번째 등장한 백조일 경우 p1에 저장
        else p2={y,x};//두 번째 등장한 백조일 경우 p2에 저장
    }
    for(int i = 0; i<4;i++){
        int ny = y+dy[i], nx = x+dx[i];
        if(ny<0||nx<0||ny>=r||nx>=c)continue;//맵 범위 벗어나는 경우
        if(vis[ny][nx])continue;//이미 방문한 경우
        if(map[ny][nx]=='X'){
            q.push({y,x});//얼음이 인접한 경우는 bfs하면서 녹여야되니 nynx말고 현재좌표인 xy를 큐에 삽입
            continue;
        }
        UnionFind({y,x},{ny,nx});//인접한 물이 있으면 일단 같은집합으로 묶어주고
        vis[ny][nx]=true;//방문표시 후
        dfs(ny,nx);//이동해서 탐색 진행
    }
}

void bfs(){//
    while(q.size()){
        pos t1 = Find(p1), t2 = Find(p2);
        if(samePos(t1,t2))return;//두 백조가 만나면 종료

        ans++;//못 만나면 ans증가
        int size = q.size();
        for(int i = 0;i < size; i++){
            pos now = q.front();
            q.pop();
            //now에서 상하좌우 돌면서 땅이면 큐에넣고 녹인 뒤 유니온파인드.
            for(int j = 0; j < 4; j++){
                int ny = now.y+dy[j], nx = now.x+dx[j];
                if(ny<0||nx<0||ny>=r||nx>=c)continue;//맵 범위 벗어나는 경우
                if(map[ny][nx]!='X')continue;//땅이 아닌 경우
                if(vis[ny][nx])continue;//이미 큐에 넣은 땅인 경우
                //이제 nynx는 맵 범위 안쪽이고, 땅인 경우만 남음
                //할일 : nynx 큐에 넣고, 녹이고, 자신과 상하좌우를 now와 유니온파인드하기.
                vis[ny][nx]=true;
                q.push({ny,nx});
                map[ny][nx]='.';
                UnionFind(now, {ny,nx});
                for(int k = 0; k < 4; k++){//얼음이 녹으며 주위 
                    int ty = ny+dy[k], tx = nx+dx[k];
                    if(ty<0||tx<0||ty>=r||tx>=c)continue;//맵 범위 벗어나는 경우
                    if(map[ty][tx]=='X')continue;//땅인 경우
                    //이제 tytx는 now와 유니온파인드해도됨. 물이고 맵 범위 안쪽이니
                    UnionFind({ty,tx},now);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>r>>c;
    p=vector<vector<pos>>(r,vector<pos>(c));
    vis=vector<vector<bool>>(r,vector<bool>(c,0));
    map=vector<string>(r);
    for(int i = 0; i<r; i++) cin>>map[i];

    for(int i = 0; i < r; i++){//유니온파인드를 위해 p배열 전부 자기자신으로 초기화
        for(int j = 0; j < c; j++) p[i][j] = {i,j};
    }

    for(int i = 0; i < r; i++){//이중포문으로 지도의 전체 구역 탐색
        for(int j = 0; j < c; j++){
            if(map[i][j]!='X' && !vis[i][j]){//아직 탐색하지 않은 물 영역을 만나면
                vis[i][j]=true;
                dfs(i,j);//주변영역 탐색해서 유니온파인드
            }
        }
    }

    //이제 분리집합(물 영역)별로 p는 통일된 상태... 두 백조가 만날 때까지 bfs하기
    bfs();
    cout<<ans;
}