#include<iostream>
#include<string> 
#include<algorithm> 
using namespace std;
int main(){
    int n;
    cin>>n;
    string s ="";
    while(n){
        s += char(n%2 + '0');
        n/=2;
    }
    reverse(s.begin(),s.end());
    for(int i = s.size()-1; i>=0; i--){
        n*=2;
        n += int(s[i]-'0');
    }
    cout<<n;
}