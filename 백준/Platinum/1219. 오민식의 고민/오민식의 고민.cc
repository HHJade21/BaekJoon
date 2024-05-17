#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, m, start, dest, a,b,c;
struct node{
    int s;
    int e;
    int w;
};
vector<node>edge;
vector<long long>profit;
vector<long long>dist;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> start >> dest >>  m;
    profit=vector<long long>(n,0);
    dist=vector<long long>(n, LLONG_MIN);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edge.push_back({a,b,c});
    }

    for(int i = 0; i < n; i++){ //i째 도시에 도착했을 때 벌 수 있는 돈을 profit배열에 저장
        cin >> profit[i];
    }

    dist[start]=profit[start];//벨만포드를 위한 시작 정점 비용 
    //벨만포드
    for(int i = 0; i <= n+50 ; i++){
        for(int j = 0; j < m; j++){//모든 에지를 확인해 갱신한다.
            int ts = edge[j].s, te = edge[j].e, tw = edge[j].w;
            if(dist[ts]==LLONG_MIN)continue;//시작지점이 아직 지나가지 못한 곳이면 continue
            else if(dist[ts]==LLONG_MAX){//양수 사이클에 연결된 출발점이었다면 도착점도 양수 사이클에 포함한다.
                dist[te]=LLONG_MAX;
            }
            else if(dist[te] < dist[ts] - tw + profit[te]){
                dist[te] = dist[ts] - tw + profit[te];
                if(i>=n-1) 
                    dist[te]=LLONG_MAX;
            }
        }
    }

    if(dist[dest]==LLONG_MIN){
        cout << "gg";
        return 0;
    }

    if(dist[dest]==LLONG_MAX){
        cout << "Gee";
    }
    else{
        cout << dist[dest];
    }
}
