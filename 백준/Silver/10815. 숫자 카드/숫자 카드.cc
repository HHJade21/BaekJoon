#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, m,tmp;
vector<int>card(500000);

bool bs(int k){
    int l=0, r = n-1, mid;

    while(l<r){
        mid = (l+r)/2;

        if(card[mid]==k)return true;
        else if(card[mid]<k){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    if(card[l]==k)return true;

    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin>>card[i];
    }
    sort(card.begin(), card.begin()+n);


    cin>>m;
    while(m--){
        cin>>tmp;
        if(bs(tmp))cout<<1 << " ";
        else cout << 0 << " ";
    }
}