#include<iostream>
using namespace std;

int main(){
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