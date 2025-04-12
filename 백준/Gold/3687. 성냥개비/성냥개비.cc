#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long t, tmp,minNum[101]={0,0,1,7,4,2,6,8,10};
    for(int i = 9; i<=100; i++){
        minNum[i]=LLONG_MAX;
        for(int j = 2; j<=7; j++){
            if(j==6)minNum[i]=min(minNum[i],minNum[i-6]*10);
            else minNum[i]=min(minNum[i],minNum[i-j]*10+minNum[j]);
        }
    }
    string maxNum[101], now="";
    for(int i = 2; i <=100; i++){
        if(i%2){
            maxNum[i] = "7"+now;
            now+="1";
        }
        else maxNum[i] = "1"+now;
    }
    cin>>t;
    while(t--){
        cin>>tmp;
        cout<<minNum[tmp] << " " <<maxNum[tmp]<<"\n";
    }
}