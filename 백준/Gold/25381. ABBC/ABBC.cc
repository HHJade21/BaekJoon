#include<iostream>
#include<deque>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin>>s;
    deque<int>dq;
    int ans=0;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='B')dq.push_back(i);
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'C' && dq.size() && dq.front()<i){
            dq.pop_front();
            ans++;
        }
    }
    for(int i = s.size()-1; i>=0; i--){
        if(s[i] == 'A' && dq.size() && i<dq.back()){
            dq.pop_back();
            ans++;
        }
    }
    cout<<ans;
}