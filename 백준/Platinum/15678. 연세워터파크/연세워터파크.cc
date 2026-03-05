#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    //{i번 다리를 마지막으로 밟을 때의 최대점수, 해당 다리 번호 i}
    priority_queue<pair<long long,int>>pq;
    long long n,d,ans=LLONG_MIN, tmp;
    cin>>n>>d;
    for(int i = 0; i < n; i++){
        cin>>tmp;//i번째 징검다리의 점수 입력
        while(pq.size() && pq.top().second < i-d)pq.pop();
        if(pq.size())tmp += pq.top().first;
        if(tmp>0)pq.push({tmp,i});
        ans = max(ans,tmp);
    }
    cout<<ans;
}