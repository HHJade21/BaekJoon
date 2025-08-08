#include <iostream>
#include<vector>
using namespace std;

int n,m,tmp;
vector<int>prime(500001, 1);//소수 판별 배열

void sieve(){//에라토스테네스의 채
    prime[0]=0;
    prime[1]=0;
    for(int i = 2; i*i<=500000; i++){
        if(!prime[i])continue;
        for(int j = i*i; j<=500000; j+=i)prime[j]=0;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    sieve();//에라토스테네스의 채
    vector<pair<int,int>>candy;//사탕의 가격,개수 저장할 벡터
    int cnt[10001]={};//가격대별 사탕 카운트할 배열
    for(int i = 0; i<n; i++){
        cin>>tmp;//i번째 사탕의 가격 입력
        cnt[tmp]++;//카운트배열에 기록
    }
    
    for(int i = 0; i<=10000; i++){//가격대별 사탕을 찾아서
        if(cnt[i])candy.push_back({i, cnt[i]});//가격과 개수를 페어로 벡터에 저장
    }
    
    vector<long long>dp(500001,0);//dp테이블 생성
    dp[0]=1;//아무 사탕도 없는 경우를 일단 추가하기
    
    for(int i = 0; i<candy.size(); i++){//사탕 종류만큼 
        long long price = candy[i].first, count = candy[i].second;
        for(int j = 500000; j>=0; j--){//사탕 가격의 총합에 따라 뒤에서부터 테이블 갱신
            if(!dp[j])continue;//j원 만큼의 사탕을 구매할 수 있는 경우의 수가 아직 없는 경우 패스
            for(int k = 1; k<=count; k++){//해당 종류의 사탕 개수만큼
                if(j+price*k>500000)break;//(j+(현재 사탕 개수*가격))원이 50만을 초과하는 경우는 조건 위반
                if(price==0)dp[j]++;
                else dp[j+price*k]+=dp[j];//현재 고른 (가격*개수)의 사탕을 구매하는 경우의 수를 테이블에 추가
            }
        }
    }
    long long res = 0;
    for(int i = 2; i<500000; i++){
        if(prime[i])res += (long long)dp[i];//가격의 합이 소수인 사탕을 구매하는 방법의 수를 정답에 합산
    }
    cout << res;//출력
}