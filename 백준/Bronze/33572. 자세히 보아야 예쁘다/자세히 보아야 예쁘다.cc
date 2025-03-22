#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n, m, sum=0, two=2;
    cin>>n>>m;
    vector<long long>a(n);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        sum+=a[i];
    }

    if(sum-n < m){
        cout<<"OUT";
        return 0;
    }

    for(int i = 0 ; i < n ;i++){
        if(a[i]>sum/two){
            cout<<"OUT";
            return 0;
        }
    }

    cout << "DIMI";
}