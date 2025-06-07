#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long tmp, sum=0,res[1000]={1,},n,m,cnt=0;
    cin>>n>>m;
    while(n--){
        cin>>tmp;
        sum = (sum + tmp)%m;
        cnt += res[sum]++;
    }
    cout<<cnt;
}