#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
long long n,a,b,c;
long long ans = LLONG_MAX;
struct edge{
    long long v;
    long long w;
};
vector<bool>vis(10001,0);
vector<vector<edge>>tree;
vector<long long>cost;
vector<long long>subNodeCnt;

void dfs(long long now,long long coost){
    vis[now]=true;
    subNodeCnt[now] = 1;
    for(auto i : tree[now]){
        long long next = i.v,nextCost=i.w;
        if(vis[next])continue;
        dfs(next,nextCost);
        cost[now]+=cost[next] + subNodeCnt[next] * nextCost;
        subNodeCnt[now] += subNodeCnt[next];
    }
}

void solve(long long now, long long sum){
    ans = min(ans, sum);
    vis[now]=true;
    for(auto i : tree[now]){
        long long next = i.v,nextCost=i.w;
        if(vis[next])continue;
        long long newSum = sum + (n-2*subNodeCnt[next])*i.w;
        solve(next, newSum);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    while(n){
        vis = vector<bool>(n,0);//정점 번호는 0번부터임.
        tree = vector<vector<edge>>(n,vector<edge>());
        cost = vector<long long>(n,0);
        subNodeCnt=vector<long long>(n,0);//여기까지 테스트케이스별 데이터 초기화
        ans = LLONG_MAX;
        for(long long i = 1 ; i < n; i++){//트리 입력받기
            cin>>a>>b>>c;
            tree[a].push_back({b,c});
            tree[b].push_back({a,c});
        }
        dfs(0,0);//일단 0번 노드를 루트로 설정해서 '서브트리의 총 비용'과 '서브트리의 크기' 구하기
        vis = vector<bool>(n,0);
        solve(0,cost[0]);
        cout << ans << "\n";
        cin>>n;
    }
}