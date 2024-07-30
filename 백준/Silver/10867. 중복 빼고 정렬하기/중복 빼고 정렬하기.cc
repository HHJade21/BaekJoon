#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int cnt[2001]={0,};//0~1000 : -1000~0 / 1001~2000 : 1~1000
    int n,tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        cnt[tmp+1000]++;
    }

    for(int i = 0; i <= 2000; i++){
        if(cnt[i])cout << i - 1000 << " ";
    }


}