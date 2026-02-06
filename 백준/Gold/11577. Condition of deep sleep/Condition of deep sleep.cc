#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,k,ans=0,tmp;
    queue<int>q;//전구를 조작할 때마다 왼쪽 끝 인덱스를 저장할 큐
    cin>>n>>k;
    for(int i = 0; i < n; i++){//가장 왼쪽 전구부터 그리디하게 진행(끌지 말지 결정)
        while(q.size()&&q.front()<= i-k)q.pop();//i번 전구에 영향을 미칠 수 없는 조작들은 삭제
        cin>>tmp;//현재 전구가 켜져있는지 아닌지
        if(n-k < i && (tmp+q.size())%2==1){//모든 전구를 끌 수 없는 경우
            cout<<"Insomnia";
            return 0;
        }
        if(i<=n-k&&(tmp+q.size())%2==1){//앞선 조작들을 적용했을 때 i번 전구가 켜져있으면
            q.push(i);//i번째부터 k개의 전구를 토글한다.
            ans++;//조작횟수 증가
        }
    }
    cout<<ans;
}