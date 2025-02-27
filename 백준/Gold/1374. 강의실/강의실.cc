#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,a,b,c;
    priority_queue<int, vector<int>, greater<int>>start;
    priority_queue<int, vector<int>, greater<int>>end;
    cin>>n;
    for(int i = 0 ; i < n;i++){
        cin>>a>>b>>c;
        start.push(b);
        end.push(c);
    }

    int now=0, ans=0;
    while(start.size()){
        if(end.top()<=start.top()){
            now--;
            end.pop();
        }
        else{
            now++;
            ans=max(ans,now);
            start.pop();
        }
    }
    cout<<ans;
}