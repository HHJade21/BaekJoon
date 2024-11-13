
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n, k, up, down, cnt=0, time=0, idx;
vector<bool>belt;
vector<int>dur;

int before(int x){
    x--;
    if(x<0)return 2*n-1;
    else return x;
}

int next(int x){
    x++;
    if(x>=2*n)return 0;
    else return x;
}


void move(int x){
    dur[x]--;
    if(dur[x]==0)cnt++;
    belt[x]=true;
}   

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;

    up=0;
    down=n-1;
    belt = vector<bool>(n*2,0);
    dur = vector<int>(n*2,0);
    cnt=0;

    for(int i = 0; i < n*2; i++){
        cin>>dur[i];
    }

    while(cnt<k){
        time++;
        //1. 컨베이어 한 바퀴 회전
        up = before(up);
        down = before(down);
        if(belt[down])belt[down]=0;//내리는 위치의 로봇 내리기


        //2. 로봇들 이동할 수 있으면 이동하기
        idx=down;
        while(idx!=next(up)){
            if(belt[before(idx)] && !belt[idx] && dur[idx]>0){
                move(idx);
                if(idx==down)belt[idx]=0;
                belt[before(idx)]=false;
            }
            idx=before(idx);
        }

        

        //3. 올리는 위치의 내구도가 0이 아니면 올리는 위치에 로봇을 올리기.
        if(dur[up]>0)move(up);

    }
    cout<<time;
}