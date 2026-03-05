#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    priority_queue<pair<long long,int>>pq;//최대점수, 계단번호 순으로 저장할 최대우선순위큐
    long long n,d,ans=-100000000000000, tmp;
    cin>>n>>d;
    for(int i = 0; i < n; i++){
        cin>>tmp;//i번째 징검다리의 점수 입력
        while(pq.size() && pq.top().second < i-d)pq.pop();//d칸 이상 멀어진 징검다리들 정보 삭제
        if(pq.size())tmp += pq.top().first;//앞에 총점수가 양수인 징검다리가 있으면 합산
        if(tmp>0)pq.push({tmp,i});//현재 계단을 밟고 얻을 수 있는 최종점수가 양수면 pq에 삽입
        ans = max(ans,tmp);//정답 갱신
    }
    cout<<ans;//출력
}


