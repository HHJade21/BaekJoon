#include<iostream>
#include<deque> 
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    deque<int>dq;
    int n,k;
    cin>>n>>k;
    for(int i = 1; i<=n; i++)dq.push_back(i);

    while(dq.size()>=k){
        dq.push_back(dq.front());
        dq.pop_front();
        for(int i = 1; i<k; i++)dq.pop_front();
    }
    cout<<dq.front();
}