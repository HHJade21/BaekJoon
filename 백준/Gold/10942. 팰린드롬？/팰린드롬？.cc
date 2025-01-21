#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, m,tmp,a,b;
vector<int>arr;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    arr = vector<int>(n+1,0);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    bool dp[n+1][n+1]={0,};

    for(int i = 1; i <= n; i++){
        int s = i, e = i;
        bool pal = true;
        while(s>0 && e<=n){
            if(pal){
                if(arr[s]==arr[e]){
                    dp[s][e]=true;
                }
                else{
                    dp[s][e]=false;
                    pal = false;
                }
            }
            else{
                dp[s][e]=false;
            }
            s--;
            e++;
        }
        s = i, e = i+1;
        pal = true;
        while(s>0 && e<=n){
            if(pal){
                if(arr[s]==arr[e]){
                    dp[s][e]=true;
                }
                else{
                    dp[s][e]=false;
                    pal = false;
                }
            }
            else{
                dp[s][e]=false;
            }
            s--;
            e++;
        }
    }


    cin>>m;
    while(m--){
        cin>>a>>b;
        if(dp[a][b])cout<<"1\n";
        else cout<<"0\n";
    }
}