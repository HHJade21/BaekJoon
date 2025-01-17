#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,m;
vector<int>ans;
vector<int>num;

void comb(int now, int depth){
    if(depth==m){
        for(auto i : ans)cout << i << " ";
        cout<<"\n";
        return;
    }

    for(int i = 1; i<= n; i++){
        ans.push_back(num[i]);
        comb(i, depth+1);
        ans.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    num=vector<int>(n+1);
    for(int i = 1; i <= n; i++){
        cin>>num[i];
    }
    sort(num.begin(), num.end());

    comb(0,0);
}