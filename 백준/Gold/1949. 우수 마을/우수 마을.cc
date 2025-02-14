#include<iostream>
#include<vector>
using namespace std;
int n,dp[10001][2],city[10001],a,b;//dp[i][0]:내가 우수마을일때, [1]:아닐때
vector<int>g[10001];
bool vis[10001];

void dfs(int now){
    vis[now]=true;
    dp[now][0]=city[now];
    dp[now][1]=0;
    for(int next : g[now]){
        if(vis[next])continue;
        dfs(next);
        dp[now][0]+=dp[next][1];
        dp[now][1]+=max(dp[next][1],dp[next][0]);
        //여기서 의문 : dp[next][1]=>여기에 합산된 값이 dp[next.next][1]이라면?
        //답 : 그렇다면 dp[next][0]이 더 클 것. 따라서 dp[now][1]에는 무조건 dp[next][0]이 합산된다. 따라서 우수마을이 아닌 것들로 둘러싸이는 상황은 발생할 수 없다!
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i = 1;i <= n;i++)cin>>city[i];//마을별 주민 수 입력
    for(int i = 1; i < n; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);//1번을 루트로 설정해놓고 트리dp 재귀 시작
    cout<<max(dp[1][0],dp[1][1]);
}