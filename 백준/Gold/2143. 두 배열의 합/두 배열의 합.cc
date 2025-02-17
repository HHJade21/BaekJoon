#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
//배열 a,b각각 가능한 모든 부 배열을 미리 저장해놓고 정렬한다.
//a의 모든 부 배열마다, 합이 t가 되는 b의 부 배열이 있는지 이분탐색으로 찾는다.
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t,n,m,cnt=0;
    long long tmp,ans=0;
    cin>>t>>n;
    vector<long long>a(n+1,0);//a의 0번부터의 구간합 전부 저장할 배열
    int asSize=n*(n+1)/2;
    vector<long long>aSum(asSize,0);//a의 부배열의 합 저장할 배열
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        a[i] = a[i-1]+a[i];//a에는 a의 원소가 아니라 0번부터의 구간합이 저장됨
    }
    for(int i = 0; i < n; i++){//a의 부 배열의 모든 경우의 수마다 합을 구해 aSum에 저장한다.
        for(int j = i+1; j<=n; j++)aSum[cnt++]=a[j]-a[i];
    }
    sort(aSum.begin(), aSum.end());//오름차순 정렬

    cin>>m;
    vector<long long>b(m+1,0);
    vector<long long>bSum(m*(m+1)/2,0);
    cnt=0;
    for(int i = 1; i <= m; i++){//b에 대해서도 a와 마찬가지의 작업을 해주고
        cin>>b[i];
        b[i] = b[i-1]+b[i];
    }
    for(int i = 0; i < m; i++){
        for(int j = i+1; j<=m; j++)bSum[cnt++]=b[j]-b[i];
    }
    sort(bSum.begin(), bSum.end());

    for(auto i : aSum){//a의 부 배열의 합 하나를 고른 뒤
        tmp = t-i;
        auto it = lower_bound(bSum.begin(), bSum.end(), tmp);//합이 t가 되는 b의 부 배열이 있는지 탐색
        if(it == bSum.end())continue;//없으면 건너뛰고
        //있으면 개수를 구해 ans에 합산
        if(*it == tmp)ans+=(upper_bound(bSum.begin(), bSum.end(), tmp)-it);
    }
    cout << ans;
}