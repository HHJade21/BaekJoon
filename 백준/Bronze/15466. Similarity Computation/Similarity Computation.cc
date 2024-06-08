#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n, a, b;

    cin >> n;
    double ki= 0.5;
    while(n--){
        cin >> a >> b;
        vector<int> aa(a);
        vector<int> bb(b);

        for(int i = 0; i < a; i++)cin>>aa[i];

        for(int j = 0; j < b; j++)cin>>bb[j];

        int kyo=0;

        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                if(aa[i]==bb[j])kyo++;
            }
        }

        double ans = (double)kyo/(double)(a+b-kyo);

        if(ans>ki) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    
}