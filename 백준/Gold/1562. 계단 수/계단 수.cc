#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<vector<vector<long long>>> dp(10,vector<vector<long long>>(101, vector<long long>(1024,0)));

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int x=2;
    for(int i = 1; i <= 9; i++){
        dp[i][1][x]=1;//한 자리 계단수 생성.
        x*=2;
    }

    int n,mask;
    long long ans = 0;
    cin >> n;

    for(int i = 2; i <= n; i++){//10억나누기 해야됨
        //여기서부터 dp테이블 채워가기
        
        mask = 1;

        //일단 이번 자리를 0으로 채울 경우 - 이전 숫자가 0,1인 경우의 수들을 가져와서 합산
        for(int j = 1; j<1024; j++){//이전 계단수의 모든 경우의 수
            dp[0][i][j|mask] = (dp[0][i][j|mask] + dp[1][i-1][j])%1000000000;
            
        }

        mask*=2;
        //이번 자리를 1~8로 채울 경우
        for(int k = 1; k<=8; k++){
            for(int j = 1; j<1024; j++){//이전 계단수의 모든 경우의 수
                dp[k][i][j|mask] = (dp[k][i][j|mask] + dp[k-1][i-1][j] + dp[k+1][i-1][j])%1000000000;
            }
            mask*=2;
        }


        //이번 자리를 9로 채울 경우
        for(int j = 1; j<1024; j++){//이전 계단수의 모든 경우의 수
            dp[9][i][j|mask] = (dp[9][i][j|mask] + dp[8][i-1][j])%1000000000;
        }
    }

    for(int i = 0; i <= 9; i++){

        ans  = (ans + dp[i][n][1023])%1000000000;
    }

    cout<<ans;
}