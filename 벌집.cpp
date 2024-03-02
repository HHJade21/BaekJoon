#include<iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n, now = 6;
    int cnt = 1;
    cin >> n;
    n--;
    while(n>0){
        n-=now;
        now+=6;
        cnt++;
    }
    cout << cnt;
}