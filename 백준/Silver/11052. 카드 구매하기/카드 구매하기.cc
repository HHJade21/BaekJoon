#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>price(n+1,0);//i장의 카드가 들어있는 카드팩의 가격을 저장할 배열
    vector<int>maxPrice(n+1,0);//카드 i장을 살 때의 최대값을 저장할 배열

    for(int i = 1; i <= n;i++){//i장이 들어있는 카드팩의 가격 입력
        cin>>price[i];
        maxPrice[i]=price[i];//일단 i장이 들어있는 카드팩의 가격이 최대값이라고 임시 초기화
    }

    for(int i = 2; i<=n; i++){//2장부터 n장까지, i장의 카드를 살 때 최대값을 dp로 maxPrice배열에 갱신
        for(int j = 0; j <= i/2; j++){//i-0부터 i/2-i/2까지 분할하는 경우의 수
            maxPrice[i]=max(maxPrice[i], maxPrice[i-j] + maxPrice[j]);//분할하고 최대값 갱신하기
        }
    }

    cout<<maxPrice[n];//n장을 사기 위해 지불해야 하는 최대값 출력
}