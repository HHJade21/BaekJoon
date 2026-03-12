#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<limits.h>
using namespace std;

struct p{//점수 기준 최소힙, 높이 기준 최대힙으로 만들어야 함.
    int score;
    int height;
    int idx;
};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q,k;
    cin>>n;
    vector<int>h(n,0);
    for(int i = 0; i < n; i++)cin>>h[i];
    cin>>q;
    for(int j = 0; j < q; j++){
        int ans=0;//이번 테스트 케이스의 정답 저장
        cin>>k;//i번째 새가 한 번에 날 수 있는 거리 입력
        deque<p>dq;//점수 낮을수록,높이 높을수록 front에 온다.
        vector<int>dp(n,0);//dp테이블(i번째 나무까지 피로도 몇으로 갈 수 있는지)
        dq.push_back({0,h[0],0});//시작 위치 정보 덱에 넣기.
        for(int i = 1; i < n; i++){
            while(dq.size()&&dq.front().idx<i-k)dq.pop_front();//멀어진 곳 제거
            //이제 i번째 칸 최소 점수(피로도) 갱신
            if(dq.front().height <= h[i])dp[i] = dq.front().score+1;
            else dp[i] = dq.front().score;
            //다음으로 덱을 정렬하기 위해 back에서 pop하고 현재 값 넣기
            while(dq.back().score>dp[i] || (dq.back().score==dp[i] && dq.back().height < h[i]))dq.pop_back();
            dq.push_back({dp[i],h[i],i});
        }
        cout<<dp[n-1]<<"\n";
    }
}