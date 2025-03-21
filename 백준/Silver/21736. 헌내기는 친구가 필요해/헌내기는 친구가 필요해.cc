#include<stdio.h> 
int n, m,sy, sx,ans=0;
char map[600][600];
int vis[600][600], dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1};

void dfs(int y, int x){
    for(int i = 0 ; i < 4; i++){
        int ny=y+dy[i], nx = x+dx[i];
        if(ny<0 || nx<0 || ny>=n || nx >=m)continue;
        if(vis[ny][nx])continue;
        if(map[ny][nx]=='X')continue;

        if(map[ny][nx]=='P')ans++;
        vis[ny][nx]=1;
        dfs(ny,nx);
    }
}

int main(){
    scanf("%d %d",&n,&m);

    for(int i = 0 ; i < n; i++){
        scanf("%s",map[i]);
        for(int j = 0; j < m; j++){
            if(map[i][j]=='I'){
                sy=i;
                sx=j;
                vis[i][j]=1;
            }
        }
    }
    dfs(sy,sx);

    if(ans)printf("%d",ans);
    else printf("TT");
}