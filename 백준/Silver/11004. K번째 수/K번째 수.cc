#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, t, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.begin()+n);
    cout << a[k-1];
}