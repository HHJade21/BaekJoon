#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,tmp,ans=0,i=0,j=0;
    cin>>n;
    vector<int>m1;//키작은여자 좋아하는 남자
    vector<int>m2;//키큰여자 좋아하는 남자
    vector<int>f1;//키큰남자 좋아하는 여자
    vector<int>f2;//키작은남자 좋아하는 여자
    for(int i = 0; i < n; i++){
        cin>>tmp;
        if(tmp<0)m1.push_back(-tmp);
        else m2.push_back(tmp);
    }
    sort(m1.begin(),m1.end());
    sort(m2.begin(),m2.end());
    for(int i = 0; i < n; i++){
        cin>>tmp;
        if(tmp>0)f1.push_back(tmp);
        else f2.push_back(-tmp);
    }
    sort(f1.begin(),f1.end());
    sort(f2.begin(),f2.end());
    while(i<m1.size() && j<f1.size()){
        if(m1[i] > f1[j]){
            ans++;
            i++;
            j++;
        }
        else i++;
    }
    i=0;
    j=0;
    while(i<m2.size() && j<f2.size()){
        if(m2[i]<f2[j]){
            ans++;
            i++;
            j++;
        }
        else j++;
    }
    cout<<ans;
}