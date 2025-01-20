#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;string s;
    cin>>n;
    vector<int>a(n,0);

    for(int i = 0;i < n;i ++){
        cin>>s;
        a[i] = (int(s[0]-'0')*10+int(s[1]-'0'))*60+int(s[3]-'0')*10+int(s[4]-'0');
    }
    sort(a.begin(),a.end());
    int ans=0,tmp,size=0;
    for(int i = 0; i < n; i++){
        if(size==0){//이전 택시가 만석으로 떠난 경우
            ans++;
            tmp = a[i]+10;
            size++;
        }
        else{//아직 이전 택시가 만석이 아닌 경우
            if(a[i]<=tmp+10){//다음 학생이 이전 택시에 탈 수 있는 경우
                size = (size+1)%3;//3명이 되면 떠나도록
            }
            else{//못 타는 경우
                ans++;//새 택시를 잡는다.
                tmp=a[i]+10;
                size=1;
            }
        }
    }
    cout<<ans;
}