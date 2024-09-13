#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    queue<int>friends;
    string s;
    int cnt[21]={0,};
    long long n, k, ans = 0;
    cin>> n >> k;

    for(int i = 0; i < k; i++){
        cin>>s;
        ans+=cnt[s.size()];

        cnt[s.size()]++;
        friends.push(s.size());
    }

    for(int i = k; i < n; i++){
        //현재 학생 입력받고 걔랑 좋은 친구 사이인 애들의 수를 구하기
        cin>>s;
        ans += cnt[s.size()];

        //맨 앞의 학생 빼기
        cnt[friends.front()]--;
        friends.pop();

        //현재 학생 큐에 넣기
        cnt[s.size()]++;
        friends.push(s.size());
    }
    cout << ans;
}