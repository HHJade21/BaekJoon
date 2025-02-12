#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, w[16][16]={0,},dp[16][(1<<16)];
//외판원 순회
int tsp(int c, int b){//현재 도시가 c, 방문 도시 목록이 b일 때 남은 외판원 순회 비용을 반환하는 함수
    if(b == (1<<n)-1){//모든 도시를 방문했을 경우(b가 111111..1인 경우)
        if(w[c][0]){//만약 현재 도시에서 시작 도시로 갈 수 있다면
            return w[c][0];//시작도시로 가는 비용을 반환
        }
        else return 100000000;//현재 도시에서 시작 도시로 갈 수 없는 경우
    }
    else if(dp[c][b]){//아직 모든 도시를 방문하진 않았지만 dp[c][b]를 이미 계산한 경우
        return dp[c][b];//그대로 반환
    }

    int tmp=100000000;
    for(int i = 0; i < n;i++){//다른 모든 도시를 체크해서
        if((b&(1<<i)) || w[c][i]==0)continue;//방문했거나, 갈 수 없으면 건너뛰기
        tmp = min(tmp, tsp(i, (b|(1<<i)))+w[c][i]);//그 도시로 이동하는 비용 + 거기서 나머지 순회하는 비용 합쳐서 최솟값이랑 비교
    }
    return dp[c][b]=tmp;//for문에서 구한 최솟값을 dp[c][b]에 저장 후 반환
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)cin>>w[i][j];
    }
    cout << tsp(0,1);//0번 도시에서 외판원 순회 시작 후 결과 출력
}