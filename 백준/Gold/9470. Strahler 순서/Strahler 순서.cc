#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t, k, n, m,cnt,a,b,ans;
    cin>>t;

    for(int kk = 1; kk <= t; kk++){
        cin>>k>>n>>m;
        cnt=0;
        ans=0;
        vector<int>ind(n+1,0);
        vector<int>g[n+1];
        vector<pair<int,int>> depth(n+1, {0,0});
        queue<int>q;

        for(int i = 0; i < m; i++){
            cin>>a>>b;
            ind[b]++;
            g[a].push_back(b);
        }

        for(int i = 1; i <= n; i++){
            if(ind[i]==0)q.push(i);
        }

        while(q.size()){
            int size = q.size();
            cnt++;
            for(int i = 0; i < size; i++){
                int now = q.front();
                q.pop();
                if(depth[now].second==0)ind[now]=1;
                else if(depth[now].second==1)ind[now]=depth[now].first;
                else ind[now]=depth[now].first+1;
                ans=max(ans, ind[now]);
                for(auto j : g[now]){
                    if(--ind[j]==0)q.push(j);
                    //만약 depth[j].first가 ind[now]보다 작으면 갱신하고 second를 1로, 같으면 second를 증가
                    if(depth[j].first<ind[now]){
                        depth[j].first=ind[now];
                        depth[j].second=1;
                    }
                    else if(depth[j].first==ind[now])depth[j].second++;
                }
            }
        }
        cout<< kk << " " << ans << "\n";
    }
}