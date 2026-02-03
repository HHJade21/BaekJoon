#include<iostream>
#include<queue>
using namespace std;
int n,t=1,cnt;
queue<int>q;
int p(int a, int b){
    int res = 1,mod=q.size();
    for(int i = 0; i < b; i++)res = (res*a-1)%mod+1;
    return res;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i = 1; i<=n; i++)q.push(i);
    while(q.size()>1){
        cnt = p(t,3);
        for(int i = 1; i<cnt; i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
        t++;
    }
    cout<<q.front();
}