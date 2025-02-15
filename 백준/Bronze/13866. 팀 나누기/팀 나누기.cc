#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int a[4],ans=10000000;
    for(int i = 0 ; i < 4; i++)cin>>a[i];

    for(int i = 0; i < 4; i++){
        for(int ii = 0; ii<4; ii++){
            for(int iii=0; iii<4; iii++){
                for(int iv=0; iv<4; iv++){
                    if(i==ii || i==iii || i==iv || ii==iii || ii == iv || iii==iv)continue;
                    ans = min(ans, abs(a[i]+a[ii]-a[iii]-a[iv]));
                }
            }
        }
    }
    cout<<ans;
}