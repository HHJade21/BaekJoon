#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<bool> isprime(4000001, 0);//0이면 소수, 1이면 소수아님
vector<int> prime;//소수만 따로 저장할 벡터. 
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int s=0, e=0, n, cnt=0, sum = 0;
    cin>>n;
    //에라토스트
    for(int i = 2; i < 2000; i++){//2부터 2000까지의 모든 소수를 찾고, 그 배수들을 걸러내기
        if(isprime[i])continue;//i가 소수가 아니면 아무것도 안하고 컨티뉴
        
        prime.push_back(i);//i가 소수가 맞으면 prime벡터에 넣어준다.
        for(int j = i*i;j<=4000000;j+=i){//i가 소수가 맞으면 i의 모든 배수들을 걸러주기
            isprime[j]=true;
        }
    }

    for(int i = 2000; i<=4000000;i++){//2000보다 크고 4000000보다 작은 남은 소수들을 벡터에 추가
        if(!isprime[i])prime.push_back(i);
    }

    
    while(s<=e){//이제 투포인터(같은방향으로 진행)

        if(sum <= n && e < prime.size())sum+=prime[e++];//합이 n보다 작으면 오른쪽애를 합에 더하고 r포인터 이동
        else sum-=prime[s++];//합이 n보다 크면 왼쪽애를 합에서 빼고 l포인터 이동
        
        if(sum==n)cnt++;//합이 정확히 n인 경우의 수를 찾으면 개수 세기

    }
    cout << cnt;
}