#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,tmp,ans=0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        pq.push(tmp);
    }
    while(pq.size()>1){
        tmp=0;
        tmp+=pq.top();
        pq.pop();
        tmp+=pq.top();
        pq.pop();
        ans+=tmp;
        pq.push(tmp);
    }
    cout << ans;
}