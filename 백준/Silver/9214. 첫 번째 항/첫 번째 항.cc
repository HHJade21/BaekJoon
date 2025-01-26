#include<iostream>
#include<string> 
#include<algorithm>
#include<vector> 
#include<limits.h> 
using namespace std;

string cho(string s){
    string res="";
    for(int i = 0; i < s.size();i+=2){
        for(int j = 0; j < int(s[i]-'0'); j++){
            res+=s[i+1];
        }
    }

    if(res.size()%2 || res==s)return res;
    return cho(res);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    for(int i = 1; i <=INT_MAX; i++){
        cin>>s;
        if(s=="0")break;
        if(s.size()%2)cout << "Test " << i << ": " << s<<"\n";
        else cout << "Test " << i << ": " << cho(s)<<"\n";
    }
}