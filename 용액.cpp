#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, lp, rp, min = INT_MAX, left, right, sum;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    lp = 0; rp = n-1; left = lp; right = rp;

    while(lp < rp){
        sum = a[lp]+a[rp];
        if(abs(sum) < min){
            min = abs(sum);
            left = lp; right = rp;
        }
        if(sum == 0){
            break;
        }
        else if(sum < 0){
            lp++;
        }
        else{
            rp--;
        }
    }

    cout << a[left] << " " << a[right];

}