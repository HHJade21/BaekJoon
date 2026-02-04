#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s,res="";
    cin>>s;
    for(auto c : s){
        if (res.size() && res[0] >= c)res = c+res;
        else res+=c;
    }
    cout<<res;
}