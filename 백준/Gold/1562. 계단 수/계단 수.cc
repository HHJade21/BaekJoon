#include<iostream>
#include<vector>
using namespace std;
int dp[101][10][1024],n, ans=0;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    for(int i = 1; i <= 9; i++)dp[1][i][1<<i]=1;//한 자리 계단수 생성.
    cin>>n;
    for(int i = 2; i<=n; i++){//2자리~n자리 계단수 개수 구하기
        for(int k = 1; k<1024; k++){
            dp[i][0][k|1] = (dp[i][0][k|1]+dp[i-1][1][k])%1000000000;//0으로 끝나는 경우
            dp[i][9][k|(1<<9)] = (dp[i][9][k|(1<<9)]+dp[i-1][8][k])%1000000000;//9로 끝나는 경우
        }
        for(int j = 1; j<=8; j++){//1~8로 끝나는 경우
            for(int k = 1; k<1024; k++)dp[i][j][k|1<<j] = (dp[i][j][k|1<<j]+dp[i-1][j-1][k] + dp[i-1][j+1][k])%1000000000;
        }
    }
    for(int j = 0; j <=9; j++)ans = (ans+dp[n][j][1023])%1000000000;
    cout<<ans;
}