#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){//솔루션 : 적게 걸리는 사람일수록 먼저 인출하면 된다.
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,sum=0,ans=0;
    cin>>n;
    vector<int>time(n);
    for(int i = 0 ; i < n; i++)cin>>time[i];//사람별 인출시간 입력

    sort(time.begin(),time.end());//시간 오름차순 정렬

    for(int i = 0 ; i < n; i++){
        //sum += time[i]*(n-i);//직관적이지 않은 풀이
        
        sum += time[i];//직관적인 풀이
        ans+=sum;//직관적인 풀이
    }
    cout<<ans;
}