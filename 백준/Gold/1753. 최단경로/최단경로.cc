#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n,m,strt,a,b,w;
//간선 정보 저장할 구조체
struct edge{//인접리스트로 그래프 구현, 우선순위큐에 정점 정보 저장
    int v;//대상(목표)정점 번호
    int w;//가중치
};
struct cmp{//우선순위큐 정렬기준 : w가 작을수록 앞에온다(최소힙)
    bool operator()(edge a, edge b){//두 간선을 정렬하는데
        return a.w>b.w;//w가 작은 애가 위로 온다.
    }
};
//시작정점에서 가까운 순서로 정점들 정렬해줄 우선순위큐
//=>다익스트라 돌릴 때, 다음 정점 뭐로 할지 정해주는 역할
priority_queue<edge, vector<edge>, cmp>pq;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>strt;//정점 개수, 간선 개수, 시작정점 번호 입력
    vector<edge>graph[n+1];//1번 정점부터 n번 정점까지, 연결된 간선들 저장할 인접리스트 그래프
    bool vis[n+1]={0,};//방문 표시 배열
    vector<int> dist(n+1, INT_MAX);//21억...으로 전부 초기화된 최단경로 배열 생성

    for(int i = 0; i < m; i++){//m개의 간선 정보 입력
        cin>>a>>b>>w;//a에서 b로 가는 가중치 w의 간선이 있다.
        graph[a].push_back({b,w});
    }//그래프 완성

    dist[strt]=0;//시작정점 자기자신으로의 최단경로는 0
    pq.push({strt,0});//우선순위큐에 다음 탐색대상으로 시작정점을 넣는다.

    while(!pq.empty()){//우선순위큐에 더이상 탐색 대상이 남아있지 않을 때까지
        int now = pq.top().v;
        pq.pop();
        if(vis[now])continue;
        vis[now]=true;//now정점을 아직 방문한 적 없으면 이제 now에서 인접정점 탐색 시작
        for(auto i : graph[now]){//now와 연결된 모든 정점에 대해서
            int next = i.v;//now와 연결된 다음 정점 : i.v
            int weight = i.w;//now와 연결된 다음 정점까지의 가중치 : i.w
            if(dist[next] > dist[now]+weight){//now를 거쳐서 가는 게 더 빠르면
                dist[next] = dist[now]+weight;//갱신해주고
                pq.push({next, dist[next]});//다음 탐색 정점 후보로 next 넣어주기
            }
        }
    }

    for(int i = 1; i <=n; i++){
        if(dist[i]==INT_MAX) cout << "INF\n";
        else cout << dist[i]<<"\n";
    }
}