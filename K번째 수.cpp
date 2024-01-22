#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a(50000000, 0);

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, t, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.begin()+n);
    cout << a[k-1];
}