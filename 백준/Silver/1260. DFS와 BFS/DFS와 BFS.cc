#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

vector<int>arr[1001]; //인접리스트
vector<int>visit(1001);
queue<int>q;

void bfs(int v){
    q.push(v);
    visit[v]=1; //방문 표시
    
    while(q.size()){
        int current=q.front(); //현재 정점
        cout<<current<<" "; //경로 출력
        q.pop();

        for(int i=0; i<arr[current].size(); i++){
            int next=arr[current][i]; //다음 정점
            if(visit[next]==0){ //방문 안했으면
                q.push(next); //큐에 삽입
                visit[next]=1; //방문 표시
            }
        }
    }
}

void dfs(int v){ //재귀!
    visit[v]=1; //방문 표시 
    cout<<v<<" "; //경로 출력

    for(int i=0; i<arr[v].size(); i++){
        int next=arr[v][i];
        if(visit[next]==0){ //연결된 정점이 방문한 적 없으면
            dfs(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n, m, v,a,b;

    cin>>n>>m>>v;
    for(int i=0; i<m; i++){ //양방향 그래프
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a); 
    }   

    for(int i=1; i<=n; i++){ //정점 번호가 작은 것 먼저 방문해야함
        sort(arr[i].begin(),arr[i].end());
    }

    dfs(v);

    visit=vector<int>(1001,0); //visit 배열 초기화 하는 방법
    cout<<"\n";

    bfs(v);
}