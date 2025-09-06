#include<iostream>
using namespace std;

bool ishansu(int x){
    if(x<100)return true;
    int ill = x%10, sib = (x%100)/10, bek=x/100;
    if(bek-sib == sib-ill)return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,ans=0;
    cin >> n;

    for(int i = 1; i <=n; i++){
        if(ishansu(i))ans++;
    }
    cout<<ans;
}