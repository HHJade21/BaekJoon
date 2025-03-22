#include<iostream>
#include<vector> 
using namespace std;
int n,m;
vector<int>ans;
vector<int>vis(9);

void comb(int now, int depth){
    if(depth<m){
        for(int i = 1; i <=n; i++){
            if(vis[i])continue;
            vis[i]=1;
            ans.push_back(i);
            comb(i, depth+1);
            vis[i]=0;
            ans.pop_back();
        }
    }
    else{
        for(auto i : ans)cout << i << " ";
        cout<<"\n";
        return;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n >> m;
    comb(0,0);
}