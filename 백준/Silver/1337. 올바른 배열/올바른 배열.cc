#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    queue<int>q;
    int n,cnt=1,ans=1;
    cin>>n;
    vector<int>v(n);
    for(int i = 0 ;i <  n; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    q.push(v[0]);
    for(int i = 1 ; i < n; i++){
        //큐의 크기가 5개가 넘어가면 pop하기
        //v[i]가 q의 front와의 차이가 4이하이면 push
        while(q.size() && v[i]>q.front()+4)q.pop();
        if(q.empty() || v[i]<=q.front()+4)q.push(v[i]);
        cnt = q.size();
        ans = max(ans, cnt);
    }
    cout << 5-ans;
}