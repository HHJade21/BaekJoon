#include<iostream>
using namespace std;
char bw[2001][2001], wb[2001][2001], tmp;
int ps1[2001][2001], ps2[2001][2001],n,m,k,chess[2001][2001], ans=9999999;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i = 1; i <=n;i++){
        int bwSum=0, wbSum=0;
        for(int j = 1; j <=m; j++){
            if((i+j)%2){
                bw[i][j]='B';
                wb[i][j]='W';
            }
            else{
                bw[i][j]='W';
                wb[i][j]='B';
            }
            cin>>tmp;
            if(tmp != bw[i][j])bwSum++;
            else wbSum++;
            ps1[i][j] = ps1[i-1][j]+bwSum;
            ps2[i][j] = ps2[i-1][j]+wbSum;
        }
    }
    for(int i = 0; i <=n-k;i++){
        for(int j = 0; j <=m-k; j++){
            ans = min(ans, ps1[i+k][j+k]-ps1[i][j+k]-ps1[i+k][j]+ps1[i][j]);
            ans = min(ans, ps2[i+k][j+k]-ps2[i][j+k]-ps2[i+k][j]+ps2[i][j]);
        }
    }
    cout<<ans;
}