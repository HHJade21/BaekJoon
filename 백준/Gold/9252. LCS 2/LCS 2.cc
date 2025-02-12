#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(b.size()+1, vector<int>(a.size()+1, 0));

    for(int i = 0; i < b.size(); i++){
        for(int j = 0; j < a.size(); j++){
            if(a[j]==b[i]){
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
        }
    }

    int i = b.size(), j = a.size();
    string ans="";
    while(i>0 && j > 0){
        if(dp[i][j] > dp[i-1][j-1] && dp[i][j] > dp[i-1][j] && dp[i][j]>dp[i][j-1]){
            ans+=a[j-1];
            i--;
            j--;
        }
        else if(dp[i][j]==dp[i-1][j]&&dp[i-1][j] > dp[i][j-1])i--;
        else j--;
    }

    cout << ans.size() << "\n";
    if(ans.size()==0)return 0;
    for(int i = ans.size()-1; i >= 0; i--)cout << ans[i];
}