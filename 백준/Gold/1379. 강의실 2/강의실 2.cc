#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,a,b,c,cnt=0,ans=0;
    cin>>n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>s;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>e;
    priority_queue<int, vector<int>, greater<int>>room;
    for(int i = 1 ; i <= n; i++){
        cin>>a>>b>>c;
        s.push({b,a});
        e.push({c,a});
        room.push(i);
    }
    vector<int>order(n+1,0);

    while(s.size()){
        if(s.top().first>=e.top().first){
            room.push(order[e.top().second]);
            e.pop();
            cnt--;
        }
        else{
            order[s.top().second]= room.top();
            room.pop();
            s.pop();
            cnt++;
            ans = max(ans, cnt);
        }
    }
    cout<<ans<<"\n";
    for(int i = 1; i <=n; i++){
        cout << order[i] << "\n";
    }
}