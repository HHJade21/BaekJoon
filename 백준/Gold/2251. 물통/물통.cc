#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool visit[201][201]={0,};
int water[3];
queue<vector<int>> bfsQ;
vector<int> ans;
vector<int> buor(vector<int>& bucket, int b1, int b2){
    vector<int> result(3,0);
    for(int i = 0; i < 3; i++) result[i]=bucket[i];
    if(bucket[b1]+bucket[b2] > water[b2]){
        result[b2] = water[b2];
        result[b1] = bucket[b1]+bucket[b2] - water[b2];
    }
    else{
        result[b2]=bucket[b1]+bucket[b2];
        result[b1]=0;
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> water[0] >> water[1] >> water[2];
    visit[0][0]=true;
    vector<int>tmp={0,0,water[2]};
    bfsQ.push(tmp);
    while(!bfsQ.empty()){
        int qsize = bfsQ.size();
        for(int i = 0; i < qsize; i++){
            vector<int>now = bfsQ.front();
            bfsQ.pop();
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(j!=k){
                        vector<int> tmp2 = buor(now, j, k);
                        if(!visit[tmp2[0]][tmp2[1]]){
                            visit[tmp2[0]][tmp2[1]] = true;
                            if(tmp2[0]==0) ans.push_back(tmp2[2]);
                            bfsQ.push(tmp2);
                        }
                    }
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << " ";
    for(int i = 1; i < ans.size(); i++) cout << ans[i] << " ";
    cout << water[2];
}