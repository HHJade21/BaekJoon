#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin>>s;
    int n = s.size();

    vector<vector<int>>dp(1001,vector<int>(1001,0));

    for(int i = 1; i <= n; i++){
        dp[i][i]=1;
    }

    for(int k = 1; k <= n; k++){//길이가 1~n인 문자열 탐색
        for(int i = 1; i<=n; i++){//i번 문자에서 시작해서
            for(int j = i+k; j<=n; j++){//j번 문자까지
                if(s[i-1]==s[j-1]){
                    dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
                }
                else{
                    dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                }
            }
        }
    }
    cout<<dp[1][n];
}