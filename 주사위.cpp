#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n, five=0, sum1=INT_MAX, sum2=INT_MAX, sum3=INT_MAX, maximum=0, ans=0;
    cin >> n;
    long long dice[6]={0,};
    for(int i = 0; i < 6; i++){
        cin >> dice[i];
        five+=dice[i];
        if(dice[i]<sum1)sum1=dice[i];//최소인 눈 찾기
        if(dice[i]>maximum)maximum=dice[i];//최대인 눈 찾기
    }
    five-=maximum;//n이 1일때를 위해 합이 최소인 다섯 개의 면을 찾기

    if(n==1){
        cout << five; 
        return 0;
    }

    for(int i = 0; i < 6; i++){//합이 최소인 인접한 두 눈 찾기
        for(int j = 0; j < 6; j++){
            if(i==j | (i+j==5))continue;//면의 번호가 같거나 인접하지 않을 경우 패스

            if(dice[i]+dice[j]<sum2)sum2=dice[i]+dice[j];//최솟값을 찾으면 갱신
        }
    }

    //합이 최소인 인접한 세 눈 찾기
    if(sum3>dice[0]+dice[1]+dice[2])sum3=dice[0]+dice[1]+dice[2];
    if(sum3>dice[0]+dice[1]+dice[3])sum3=dice[0]+dice[1]+dice[3];
    if(sum3>dice[0]+dice[4]+dice[2])sum3=dice[0]+dice[4]+dice[2];
    if(sum3>dice[0]+dice[3]+dice[4])sum3=dice[0]+dice[3]+dice[4];
    if(sum3>dice[5]+dice[1]+dice[2])sum3=dice[5]+dice[1]+dice[2];
    if(sum3>dice[5]+dice[1]+dice[3])sum3=dice[5]+dice[1]+dice[3];
    if(sum3>dice[5]+dice[4]+dice[2])sum3=dice[5]+dice[4]+dice[2];
    if(sum3>dice[5]+dice[3]+dice[4])sum3=dice[5]+dice[3]+dice[4];
    //이제 sum3에는 인접한 세 눈의 합 중 최솟값이 저장됨

    ans+=(n-2)*(n-2)*sum1 + 4*(n-2)*(n-1)*sum1;
    ans+=(2*n-3)*4*sum2;
    ans+=sum3*4;

    //test
    //cout << "sum1, sum2, sum3 = " << sum1 << ", " << sum2 << ", " << sum3 << ".\n";
    cout << ans;
}