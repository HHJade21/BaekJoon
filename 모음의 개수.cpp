#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int cnt=0;
    for(auto i : s){
        if(i=='a' || i=='e' || i == 'i' || i == 'o' || i == 'u')cnt++;
    }
    cout<<cnt;
}