#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, k, cnt = 2, now;
queue<int> bfsQ;
vector<bool> visit(200001, 0);
vector<int> ans;
vector<int> time(200001, 0);


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    visit[n] = true;
    time[n] = 1;
    bfsQ.push(n);

    while(!bfsQ.empty()){
        int size = bfsQ.size();
        for(int j = 0; j < size; j++){
            now = bfsQ.front();
            if(now == k){
                break;
            }
            int next[3] = {now-1, now+1, now*2};
            for(int i = 0; i < 3; i++){
                if(next[i] >= 0 && next[i] <= 200000 && !visit[next[i]]){
                    visit[next[i]] = true;
                    time[next[i]] = cnt;
                    bfsQ.push(next[i]);
                }
            }
            bfsQ.pop();
        }
        if(now == k)
            break;
        cnt++;
    }

    now = k;
    ans.push_back(k);
    while(now != n){
        if(now-1 >= 0 && now-1 <= 200000 && time[now-1] == time[now]-1){
            ans.push_back(now-1);
            now--;
            continue;
        }
        else if(now+1 >= 0 && now+1 <= 200000 && time[now+1] == time[now] - 1){
            ans.push_back(now+1);
            now++;
            continue;
        }
        else{
            ans.push_back(now/2);
            now /= 2;
            continue;
        }
    }
    cout << cnt-2 << "\n";
    for(int i = ans.size()-1; i>=0; i--){
        cout << ans[i] << " ";
    }
}