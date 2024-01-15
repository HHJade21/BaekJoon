#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int cnt = 0, n;


void nq(int idx, vector<int> q, vector<bool> exist){//idx는 현재 퀸의 번호.
    if(idx == n){
        cnt++;
        return;
    }
    //idx번째 행의 퀸을 놓을 수 있는 열마다 적절한지 확인하여 재귀
    for(int i = 0; i < n; i++){ //i는 idx번째 퀸을 놓을 위치.
        if(!exist[i] && !exist[n + idx + i] && !exist[4*n + i - idx]){
            q[idx] = i;
            vector<bool> ex = exist;
            ex[i] = true;
            ex[n + idx + i] = true;
            ex[4*n + i - idx] = true;
            nq(idx+1, q, ex);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    vector<int> queens(n);
    for(int i = 0; i < n; i++){
        queens[0] = i;
        vector<bool> exist(5*n, 0);
        exist[i] = true;
        exist[n + i] = true;
        exist[4*n + i] = true;
        nq(1, queens, exist);
    }
    cout << cnt;
}