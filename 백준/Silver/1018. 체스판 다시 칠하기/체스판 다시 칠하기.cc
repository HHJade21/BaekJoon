#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    char chess1[50][50], chess2[50][50];
    string map[50];
    int n,m, ans=100000000,sum1,sum2;
    cin>>n>>m;
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            if((i+j)%2==1){
                chess1[i][j]='W';
                chess2[i][j]='B';
            }
            else{
                chess1[i][j]='B';
                chess2[i][j]='W';
            }
        }
    }
    for(int i = 0; i <n; i++){
        cin>>map[i];
    }

    for(int i = 0; i <= n-8; i++){
        for(int j = 0; j <= m-8; j++){
            //여기서부터 8*8사이즈로 체스판 답안 1 2랑 주어진 지도랑 비교
            sum1 = 0;
            sum2 = 0;
            for(int k = 0; k < 8; k++){
                for(int l = 0; l < 8; l++){
                    if(map[i+k][j+l]!=chess1[i+k][j+l]){
                        sum1++;
                    }
                    if(map[i+k][j+l]!=chess2[i+k][j+l]){
                        sum2++;
                    }
                }
            }
            ans = min(ans, sum1);
            ans = min(ans, sum2);
        }
    }
    cout << ans;
}