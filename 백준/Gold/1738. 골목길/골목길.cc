#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, m, s, e, w, asize=0;

struct node{
    int a;
    int b;
    int weight;
};

vector<node> edge;
vector<long long> dist;
vector<vector<pair<int,int>>>reverseEdge;
vector<int>before;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    dist = vector<long long>(n+1,LLONG_MIN);
    reverseEdge=vector<vector<pair<int,int>>>(n+1);//역추적을 위한 인접리스트
    before = vector<int>(n+1,0);
    for(int i = 0; i < m; i++){
        cin >> s >> e >> w;
        edge.push_back({s,e,w});
        reverseEdge[e].push_back({s,w});//역추적 인접리스트의 [도착지점]에 {출발지점, 비용}저장
    }

    dist[1]=0;

    for(int i = 0; i <= n+100; i++){
        for(int j = 0; j < edge.size(); j++){
            int ts = edge[j].a, te = edge[j].b, tw = edge[j].weight;
            if(dist[ts]==LLONG_MIN)continue;//아직 집에서 연결되지 않은 교차점이면 패스
            else if(dist[ts]==LLONG_MAX){//양수 사이클에 새로운 교차점이 연결되면
                dist[te]=LLONG_MAX;//양수 사이클에 추가해준다.
            }
            else if(dist[te] < dist[ts]+tw){//연결된 교차점에서 새롭게 연결되는 교차점이면
                dist[te]=dist[ts]+tw;//최대금품량에 맞춰 갱신
                before[te]=ts;
                if(i>=n) dist[te]=LLONG_MAX;//양수 사이클이면 표시해주기
            }
        }
    }

    if(dist[n]==LLONG_MIN || dist[n]==LLONG_MAX){//연결되지 않았거나 양수 사이클에 연결되어 있는 경우
        cout << -1;
        return 0;
    }


    //콘도가 집에서 연결되어 있을 경우
    int now = n;
    vector<int> ans;

    while(now>1){
        ans.push_back(now);
        now = before[now];
    }

    ans.push_back(1);

    for(int i = ans.size()-1; i>=0; i--) cout << ans[i] << " ";
}