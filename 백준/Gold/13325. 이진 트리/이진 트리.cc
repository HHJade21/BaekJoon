#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<math.h>
using namespace std;
int k;
int ans=0;
vector<int>tree(2100000,0);

int dfs(int now){
    if((now*2+1)>=k){//리프노드인 경우
        ans+=tree[now];
        return tree[now];
    }
    else{//아닌 경우
        int left = dfs(now*2), right = dfs(now*2+1);
        ans += abs(left-right)+tree[now];
        return max(left,right)+tree[now];
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>k;
    k = 1<<(k+1);
    for(int i = 2; i <k; i++){//노드번호는 1부터 k-1이고, 루트노드는 진입 엣지가 없으니까.
        cin>>tree[i];
    }
    dfs(1);
    cout << ans;
}