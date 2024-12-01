#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    int map[50][50]={0,};
    for(int i = 0; i < n; i++)cin>>map[i][0];
    for(int i = 1; i < m; i++)cin>>map[n-1][i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j<m;j++){
            bool clear = 1;

            for(int k = 0; k < n; k++){
                if(map[k][0]!=abs(k-i)+j){
                    clear = false;
                }
            }
            for(int k = 1; k < m; k++){
                if(map[n-1][k]!=abs(n-1-i)+abs(j-k)){
                    clear = false;
                }
            }

            if(clear){
                cout << i+1 << " " <<j+1;
                return 0;
            }
        }
    }
    
}