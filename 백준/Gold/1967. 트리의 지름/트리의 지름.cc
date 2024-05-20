#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<vector<pair<int,int>>> g;//first는 연결노드, second는 가중치
vector<bool>visited;
vector<int> linkCnt;

int n,s,e,w,ans=0,tmp;

void dfs(int now){
    int size = g[now].size();
    for(int i = 0; i<size; i++){//현재 정점과 연결된 모든 정점에대하여
        int next = g[now][i].first;//연결된 다음 정점 번호
        if(visited[next])continue;//방문한 애면 패스

        if( linkCnt[next]==1){//아직 방문하지 않았는데 리프면 ans랑 비교
            ans = max(ans, tmp+g[now][i].second);
        }
        else{//아직 방문하지 않았고 리프가 아니면
            tmp+=g[now][i].second;//현재 지름 값 증가시키고
            visited[next]=true;
            dfs(next);//재귀
            tmp-=g[now][i].second;//재귀 끝나면 tmp와 visited리셋
            visited[next]=false;
        }


    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    g=vector<vector<pair<int,int>>>(n+1);
    visited=vector<bool>(n+1,0);
    linkCnt=vector<int>(n+1,0);//0이면 리프노드 1이면 아님

    for(int i = 1; i< n; i++){
        cin >> s >> e >> w;
        g[s].push_back({e,w});//각 노드의 인접리스트에 간선 넣어주고
        g[e].push_back({s,w});
        linkCnt[s]++;
        linkCnt[e]++;
    }


    for(int i = 1; i <= n; i++){//모든 노드에 대하여
        if (linkCnt[i]>1)continue;//리프노드가 아니라면 지름을 구할 수 없으니 패스

        visited=vector<bool>(n+1,0);//dfs시작하기 전에 방문배열 초기화하고
        tmp=0;//지름의 크기 갱신해나갈 변수 초기화
        visited[i]=true;//첫 정점은 방문했다고 표시
        dfs(i);
    }

    cout<<ans;
}