#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int>>dp(1000,vector<int>(1000,0));//dp[i][j] : i번문자부터 j번문자까지 팰.부.문의 개수

    for(int i = 0; i < n; i++){
        dp[i][i]=1;//한 글자짜리 문자열은 자기 자신이 팰린드롬 문자열이기 때문에 dp[i][i]는 전부 1
    }

    for(int k = 1; k <= n; k++){//길이가 1~n인 문자열 탐색(대각선으로 진행할 거라서 길이 먼저 설정.)
        for(int i = 0; i<n; i++){//i번 문자에서 시작해서
            for(int j = i+k; j<n; j++){//j번 문자까지
                if(s[i]==s[j]){//i번 글자랑 j번 글자가 같으면(문자열이라서 인덱스는 i-1, j-1로 참조함)
                    dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
                }
                else{
                    dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                }
            }
        }
    }
    cout<<dp[0][n-1];
}