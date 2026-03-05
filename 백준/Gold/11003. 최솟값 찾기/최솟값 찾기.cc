#include<iostream>
#include<deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    deque<pair<int,int>>dq;
    int n,l,tmp;
    cin>>n>>l;
    for(int i = 0; i < n; i++){
        cin>>tmp;
        //덱의 front에 최솟값을 저장할 것.
        while(dq.size() && dq.front().second <= i-l)dq.pop_front();
        while(dq.size() && dq.back().first > tmp)dq.pop_back();
        dq.push_back({tmp,i});
        cout<<dq.front().first<<" ";
    }
}