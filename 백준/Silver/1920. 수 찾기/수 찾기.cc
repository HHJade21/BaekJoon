#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    cin>>m;
    
    for(int i = 0; i < m; i++){
        int s=0, e=n-1, m,tmp;
        cin>>tmp;
        while(s<=e){
            m = (s+e)/2;
            if(a[m]==tmp) break;
            else if(a[m]<tmp) s = m+1;
            else e = m-1;
        }
        if(a[m]==tmp)cout<<1<<"\n";
        else cout<< 0 << "\n";
    }
    
}