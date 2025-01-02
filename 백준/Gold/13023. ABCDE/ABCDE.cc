#include<iostream>
#include<vector>
#include<queue>
#include <stack>
#include<algorithm>
#include<limits.h>
#include <cstring>
// a-b-c-d-e 만족하려면 깊이 4여야함
using namespace std;
int N,M,a,b;
bool visit[10000];
bool bro[2000][2000];
bool found=false;
vector<int>g[2000];


void dfs(int node,int depth){
    // cout << node << ".  depth : " << depth << "\n";
    if(depth==4){
        found=true;
        return;
    } 

    for(int i=0;i<g[node].size();i++){
        int next = g[node][i];
        if(visit[next]){//방문 0 --> 건너뜀
            continue;
        }
        if(found) break;

        visit[next]=true;
        dfs(next,depth+1);
    }

    visit[node]=false;   

}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>N>>M; //사람수와 친구 관계 수

    for(int i=0;i<M;i++){
        cin>>a>>b;//친구 관계 표현 변수(a,b 친구)
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=0;i<N;i++){
        memset(visit,0,sizeof(visit));
        visit[i]=true;
        dfs(i,0);
        if(found) break;
    }

    
    if(found) cout<<1<<"\n";
    else cout<< 0 <<"\n";


    return 0;
}