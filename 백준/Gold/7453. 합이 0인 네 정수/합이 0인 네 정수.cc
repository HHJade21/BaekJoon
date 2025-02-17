#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
long long a[4000],b[4000],c[4000],d[4000], tmp,ans;
int n,cnt;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i = 0 ; i < n; i++){
        cin>> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<long long>sumAB(n*n);//a와 b원소들의 합을 저장할 배열
    vector<long long>sumCD(n*n);//c와 d원소들의 합을 저장할 배열
    cnt=0;
    for(int i = 0; i < n; i++){//ab, cd 각각 원소들의 합 종류 구하기
        for(int j = 0; j < n; j++){
            sumAB[cnt] = a[i] + b[j];
            sumCD[cnt] = c[i] + d[j];
            cnt++;
        }
    }//이제 a,b의 합이 만들어졌음. 정렬해주고
    sort(sumAB.begin(), sumAB.end());
    sort(sumCD.begin(), sumCD.end());

    for(int i = 0; i < n*n; i++){
        tmp = -sumAB[i];
        auto it = lower_bound(sumCD.begin(), sumCD.end(), tmp);
        if(it == sumCD.end())continue;
        if(*it == tmp) ans += (upper_bound(sumCD.begin(), sumCD.end(), tmp)-it);
    }
    cout << ans;
}