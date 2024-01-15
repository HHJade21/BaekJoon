#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, k, sec = 0;
    int now, size;
    set<int> tq;
    cin >> n >> k;
    vector<int> route(200001, 0);
    vector<bool> visit(200001, 0);
    route[n] = 1;
    visit[n] = true;
    queue<int> bfsQ;
    bfsQ.push(n);

    while(!bfsQ.empty()){
        size = bfsQ.size();
        tq.clear();
        for(int j = 0; j < size; j++){
            now = bfsQ.front();
            if(now == k){
                break;
            }
            int next[3] = {now-1, now+1, now*2};

            for(int i = 0; i < 3; i++){
                if(next[i] >= 0 && next[i] <= 200000 && !visit[next[i]]){
                    route[next[i]] += route[now];
                    tq.insert(next[i]);
                }
            }
            bfsQ.pop();
        }
        if(now == k)
            break;
        for(int a : tq){
            bfsQ.push(a);
            visit[a] = true;
        }
        sec++;
    }
    
    cout << sec << "\n" << route[k];
}