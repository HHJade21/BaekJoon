#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    


    int n, q;
    cin >> n >> q;
    vector<long long>a(n);
    vector<long long> sum(n,0);

    cin>>a[0];
    sum[0]=a[0];

    for(int i = 1; i < n; i++){
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
    }

    //이러면 전체 수열, 전체 구간합 나옴.

    int begin=0, cmd, value, x,y;


    while(q--){
        cin >> cmd;
        if(cmd==1){
            cin >> value;
            begin = (begin + n - value)%n;
        }
        else if(cmd==2){
            cin >> value;
            begin = (begin + value)%n;
        }
        else{
            cin >> x >> y;
            if((begin+x-1)%n <= (begin+y-1)%n){
                if((begin+x-1)%n==0){
                    cout << sum[(begin+y-1)%n] << "\n";
                }
                else {
                    cout << sum[(begin+y-1)%n] - sum[(begin+x-2)%n] << "\n";
                }
            }
            else{
                cout << sum[n-1] - sum[(begin+x-2)%n] + sum[(begin+y-1)%n] << "\n";
            }
        }
    }

}