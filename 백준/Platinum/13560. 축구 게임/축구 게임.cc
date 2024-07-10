#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n, sum=0, zero=0, allwin=0,tmp;
    vector<int> a;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>tmp;
        a.push_back(tmp);
        if(tmp== 0)zero++;
        else if(tmp== n-1)allwin++;
        sum+=tmp;
    }

    if(zero>1)cout<<-1;
    else if(allwin>1)cout<<-1;
    else if(sum != (n*(n-1))/2)cout<<-1;
    else{
        sort(a.begin(), a.end());
        sum=0;
        for(int i = 0; i < n; i++){
            sum+=a[i];
            if(sum < i*(i+1)/2){
                cout << -1;
                return 0;
            }
        }
        cout << 1;
    }
}