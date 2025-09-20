#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin>>s;
    int idx=0;

    for(int i = 1; i<=1000000; i++){
        string tmp = to_string(i);
        for(auto c : tmp){
            if(s[idx]==c)idx++;
            if(idx==s.size()){
                cout<<i;
                return 0;
            }
        }
    }
}