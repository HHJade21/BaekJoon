#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, cnt = 0, i = 2;
    cin >> n;
    n--;
    while(n>0){
        if(n%i == 0) 
            cnt++;
        n -= i++;
    }
    cout << cnt+1;
}