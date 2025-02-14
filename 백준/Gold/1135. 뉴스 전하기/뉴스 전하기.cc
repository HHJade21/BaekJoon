#include<iostream>
#include<queue>
using namespace std;
int n,a;
vector<int>g[50];
int dfs(int now){
    if(g[now].empty()) return 0;//리프노드면 0 리턴
    priority_queue<int>pq;
    for(auto i : g[now])pq.push(dfs(i));
    int tmp=1,res=0;
    while(pq.size()){
        res = max(res,pq.top()+(tmp++));
        pq.pop();
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    cin>>a;
    for(int i = 1; i < n; i++){
        cin>>a;
        g[a].push_back(i);//직속상사 자식노드로 i번사원 추가
    }
    cout<<dfs(0);
}