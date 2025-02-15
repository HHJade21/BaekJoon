#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    string s;
    int ac=0,bc=0;
    cin>>s;
    for(auto i : s){
        if(i=='A')ac++;
        else bc++;
    }
    if(ac==bc)cout<<"Tie";    
    else if(ac>bc)cout<<"A";
    else cout<<"B";
}