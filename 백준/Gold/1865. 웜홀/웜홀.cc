#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int t, n, m, w, sp, ep, weight;
bool mCycle=false;
vector<long long>dist;
struct node{
    int s;
    int e;
    int w;
};
vector<node>edge;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> m >> w;
        mCycle=false;
        dist=vector<long long>(n+1, 1000000000000);
        edge = vector<node>();

        for(int i = 0; i < m; i++){
            cin >> sp >> ep >> weight;
            edge.push_back({sp, ep, weight});
            edge.push_back({ep, sp, weight});
        }
        for(int i = 0; i < w; i++){
            cin >> sp >> ep >> weight;
            edge.push_back({sp, ep, -weight});
        }
        dist[1]=0;

        int esize= edge.size();
        for(int i = 1; i < n; i++){
            for(int j = 0; j < esize; j++){
                if(dist[edge[j].e]>dist[edge[j].s]+edge[j].w)
                    dist[edge[j].e]=dist[edge[j].s]+edge[j].w;
            }
        }

        for(int j = 0; j < esize; j++){
            if(dist[edge[j].e]>dist[edge[j].s]+edge[j].w)
                mCycle=true;
        }

        if(mCycle) cout << "YES\n";
        else cout << "NO\n"; 
    }
}