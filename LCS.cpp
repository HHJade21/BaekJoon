#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    int as = a.size(), bs = b.size(), m = 0;
    vector<int> dp(as+1, 0);
    for(int i = 0; i < bs; i++){
        vector<int>td = dp;
        for(int j = 0; j < as; j++){
            if(a[j] == b[i]) td[j+1] = dp[j]+1;
            else td[j+1] = max(td[j], td[j+1]);
        }
        dp = td;
    }
    for(auto i : dp)
        m = max(i, m);
    cout << m;
}