#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n, m,sum;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;

    vector<int>dp(n,0);
    vector<int>num(n,0);

    for(int i = 0; i < n; i++){
        cin>>num[i];
    }

    for(int i = n-2; i >= 0; i--){//dp테이블 뒤에서부터 갱신
        sum=0;
        int tmp=INT_MAX;

        for(int j = i; j < n; j++){//이번 줄에 i번째까지 들어갈때의 총점수
            if(sum>0)sum++;
            sum+=num[j];

            if(sum>m)break;
            if(j==n-1){
                tmp=0;
                break;
            }
            tmp = min(tmp, (m-sum)*(m-sum)+dp[j+1]);
        }
        dp[i]=tmp;
    }

    cout << dp[0];
}