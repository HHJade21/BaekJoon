#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, lion[100001][3];
    cin>>n;

    //첫째 줄에
    lion[1][0]=1;//왼쪽에만 배치함
    lion[1][1]=1;//오른쪽에만 배치함
    lion[1][2]=1;//배치하지 않음

    for(int i = 2; i <=n; i++){//둘째~n번째 줄에
        lion[i][0] = (lion[i-1][1]+lion[i-1][2])%9901;//왼쪽에만 배치하는 경우의 수 : 이전 줄의 오른쪽에만 배치했거나, 배치하지 않았음
        lion[i][1] = (lion[i-1][0]+lion[i-1][2])%9901;//오른쪽에만 배치하는 경우의 수 : 이전 줄의 왼쪽에만 배치했거나, 배치하지 않았음
        lion[i][2] = (lion[i-1][0]+lion[i-1][1]+lion[i-1][2])%9901;//배치하지 않는 경우의 수 : 이전 줄의 배치상태가 어떻든 항상 가능
    }

    cout << (lion[n][0] + lion[n][1] + lion[n][2])%9901; //n번째 줄까지 사자를 배치할 수 있는 모든 경우의 수 출력
}

