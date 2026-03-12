#include<iostream>
#include<deque>
#include<vector>
using namespace std;
//구해야 하는 것 : p[i]-p[j]+dp[j-1]의 최댓값
//                  => dp[j-1]-p[j]을 dq에 저장해놓고 단조감소덱으로 구현.
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    deque<pair<long long,int>>dq;//front: dp[j-1]-p[j]의 최댓값이 온다. 
    int n,k;
    long long a;
    cin>>n>>k;
    vector<long long>p(n+1,0);//누적합 배열
    vector<long long>dp(n+1,0);//dp테이블 : i번째까지 얻을 수 있는 최대 점수
    dq.push_back({0,0});
    for(int i = 1; i <= n; i++){
        cin>>a;//i번째 소의 효율 입력
        p[i] = a + p[i-1];//i번째 소까지의 누적합 저장
        while(dq.size()&&dq.front().second<i-k)dq.pop_front();//너무 멀리 떨어진 소는 front에서 삭제
        dp[i] = max(p[i] + dq.front().first,dp[i-1]);;//dp값 갱신
        while(dq.size()&&dq.back().first<dp[i-1]-p[i])dq.pop_back();//단조감소덱을 위해 back제거
        dq.push_back({dp[i-1]-p[i], i});//덱에 푸쉬
        //dp[i]=max(dp[i],//dp값 앞에꺼가 더 크면 뒤로 밀기
    }
    cout<<dp[n];
}