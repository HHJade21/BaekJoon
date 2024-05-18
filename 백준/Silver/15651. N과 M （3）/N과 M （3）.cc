#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,m;
vector<int>ans;
void comb(int now, int depth){
    if(depth<m){
        for(int i = 1; i <= n; i++){
            ans.push_back(i);
            comb(i, depth+1);
            ans.pop_back();
        }
    }
    else{
        for(auto i : ans)cout << i  << " ";
        cout<<"\n";
    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    comb(0, 0);
}