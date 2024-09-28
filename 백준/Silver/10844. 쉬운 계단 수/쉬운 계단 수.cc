#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n=0, sum=0;
    cin >> n;
    vector<vector<int>>dp (10,vector<int>(101,0));
    
    for(int i=1; i<=9; i++){
        dp[i][1]=1;
    }
    //구할 것이 dp[a][b]라고 하면 dp[a][b] = dp[a-1][b+1] + dp[a-1][b-1]
    for(int i=2; i<=100; i++){
        dp[0][i] = dp[1][i-1];
        dp[9][i] = dp[8][i-1];

        for(int j=1; j<9; j++){
            dp[j][i] = (dp[j+1][i-1] + dp[j-1][i-1])%1000000000;
        }
    }
    for(int i=0; i<=9; i++){
        sum += dp[i][n];
        sum %= 1000000000;
    }
    cout << sum;
    
}