#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    //블루레이의 크기에 대해서 매개변수 탐색. 
    int a,b;

    while(a!=0 || b!=0){
        cin>>a>>b;

        if(a!=0||b!=0){
            cout << a+b<<"\n";
        }
    }
}