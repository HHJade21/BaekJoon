#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, k,ans=0;
queue<int>q;
bool vis[100001]={0,};
int newX[3];

void bfs(){
    while(q.size()){
        int size = q.size();
        ans++;//초 증가
        for(int i = 0; i < size; i++){//여기서부터 평범한 bfs
            int now = q.front();
            q.pop();

            newX[0]=now-1;//수빈이가 이동할 수 있는 세 좌표를 newX배열에 모두 넣고
            newX[1]=now+1;
            newX[2]=now*2;

            for(int j = 0; j < 3; j++){
                int next = newX[j];
                if(next == k)return;//동생을 찾았다면 즉시 함수 종료
                if(next<0 || next>100000 || vis[next])continue;//맵 벗어나거나 이미 방문했는가?
                vis[next] = true;
                q.push(next);
            }
        }
    }
}   

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    if(n==k){
        cout<<0;
        return 0;
    }
    q.push(n);
    vis[n]=true;
    bfs();
    cout<<ans;
}