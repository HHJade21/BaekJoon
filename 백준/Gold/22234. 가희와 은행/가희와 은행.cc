#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

struct p{
    int id;
    int work;
    int time;
};
bool cmp(p a, p b){
    return a.time<b.time;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m,t,w,a,b,c,now=0,next=0, currentWorkTime;
    queue<p> q;
    cin>>n>>t>>w;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        q.push({a,b,0});
    }
    cin>>m;
    vector<p>wait;
    for(int i = 0; i< m; i++){
        cin>>a>>b>>c;
        wait.push_back({a,b,c});
    }
    sort(wait.begin(),wait.end(),cmp);
    while(next<m && wait[next].time==0)q.push(wait[next++]);
    currentWorkTime=t;
    while(now<w){
        while(next<m&&wait[next].time==now+1)q.push(wait[next++]);
        cout<<q.front().id<<"\n"; 
        currentWorkTime--;
        q.front().work--;
        if(q.front().work==0){
            currentWorkTime = t;
            q.pop();
        }
        else if(currentWorkTime==0){
            q.push(q.front());
            q.pop();
            currentWorkTime=t;
        }
        now++;
    }
}