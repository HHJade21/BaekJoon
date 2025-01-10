#include<iostream>
#include<vector>
using namespace std;
int ans=0,n;
vector<int>queens;
vector<bool>vis;

void nQueen(int depth){
    if(depth==n){
        ans++;
        return;
    }

    for(int i = 0; i < n; i++){
        if(!vis[i] && !vis[n+depth+i] && !vis[4*n+i-depth]){
            queens[depth]=i;
            vis[i]=true;
            vis[n+depth+i]=true;
            vis[4*n+i-depth]=true;
            nQueen(depth+1);
            vis[i]=false;
            vis[n+depth+i]=false;
            vis[4*n+i-depth]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    queens = vector<int>(n,0);
    for(int i = 0; i < n; i++){
        vis = vector<bool>(n*5,0);
        queens[0]=i;
        vis[i]=true;
        vis[n+i]=true;
        vis[4*n+i]=true;
        nQueen(1);
        vis[i]=false;
        vis[n+i]=false;
        vis[4*n+i]=false;
    }

    cout<<ans;
}