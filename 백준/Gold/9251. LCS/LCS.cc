#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string a,b;
    cin>>a>>b;
    int as = a.size(), bs=b.size(), dp[1001][1001]={};
    for(int i = 1; i <= as; i++){//문자열 a의 i번째 글자가 추가됐을 때
        for(int j = 1; j <= bs; j++){//b의 j번째 글자 추가
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[as][bs];
}