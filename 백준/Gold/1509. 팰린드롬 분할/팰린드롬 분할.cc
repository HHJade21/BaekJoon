#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    int n;
    cin>>s;
    n=s.size();
    vector<vector<bool>>isPal(n, vector<bool>(n,0));
    //i번째 글자부터 j번째 글자까지 팰린드롬인지 판별해 dp[i][j]전부 채우기
    //팰린드롬? 문제에서 했던 것과 같은 과정
    for(int i = 0; i < n; i++){
        //먼저 글자의 개수가 홀수인 팰린드롬 전부 찾기
        int l = i, r = i;
        bool flag = true;
        while(0<=l&&r<n){
            if(!flag)isPal[l][r]=false;
            else if(s[l]==s[r])isPal[l][r]=true;
            else{
                flag = false;
                isPal[l][r]=false;
            }
            l--;
            r++;
        }
        //다음으로 글자의 개수가 짝수인 팰린드롬 전부 찾기
        l = i, r = i+1;
        flag = true;
        while(0<=l&&r<n){
            if(!flag)isPal[l][r]=false;
            else if(s[l]==s[r])isPal[l][r]=true;
            else{
                flag = false;
                isPal[l][r]=false;
            }
            l--;
            r++;
        }
    }

    //이제 1차원dp테이블 만들어서 갱신할거임
    vector<int>dp(n+1,INT_MAX);//dp[i] : 문자열의 i번째 글자까지만 있을 때, 팰린드롬 분할의 개수의 최솟값
    dp[0]=0;//글자가 0개만 있을땐 분할의 개수가 0개라고 설정
    for(int i = 1; i <= n; i++){//dp[i]찾기
        for(int j = i; j >0; j--){//i번째 글자부터 앞쪽으로 첫 번째 글자까지 탐색
            //만약 j번째 글자부터 i번째 글자까지 팰린드롬이라면
            //dp[i], 즉 i번째 글자까지의 팰린드롬 분할 최소개수는
            //j번째 글자 이전까지의 팰린드롬 분할 최소개수에 +1 한 것(j번째부터 i번째까지 하나의 팰린드롬으로 분할되니까.)과
            //기존 dp[i]의 값 중 더 작은 값으로 갱신한다. 
            if(isPal[j-1][i-1])dp[i]=min(dp[i],dp[j-1]+1);
        }
    }
    cout<<dp[n];
}