#include<iostream>
#include<deque> 
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    deque<char>dq;
    cin>>s;
    for(auto c : s){
        if (dq.size() && dq.front() >= c)dq.push_front(c);
        else dq.push_back(c);
    }
    while(dq.size()){
        cout<<dq.front();
        dq.pop_front();
    }
}