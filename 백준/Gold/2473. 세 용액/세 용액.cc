#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, l, r, ml=0, mr=0, mp=0;
    long long min = 3000000001;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++)cin >>a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        l = 0;
        r = n-1;
        while(l<r){
            if(l==i){
                l++;
                continue;
            }
            else if(r==i){
                r--;
                continue;
            }

            if(min > abs(a[i]+a[l]+a[r])){
                min = abs(a[i]+a[l]+a[r]);
                ml = l;
                mr = r;
                mp = i;
            }

            if(a[i]+a[l]+a[r] < 0) l++;
            else r--;

        }
    }
    if(mp < ml) swap(mp, ml);
    else if(mr < mp) swap(mp, mr);

    cout << a[ml] << " " << a[mp] << " " << a[mr];
}