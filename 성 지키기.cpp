#include<iostream>
using namespace std;
int main(){
    int r[50] = {0,};
    int c[50] = {0,};
    int n, m, rc, cc;
    cin >> n >> m;
    rc = n;
    cc = m;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == 'X'){
                if(r[i] == 0){
                    rc--;
                    r[i] = 1;
                }
                if(c[j] == 0){
                    cc--;
                    c[j] = 1;
                }
            }
        }
    }
    cout << max(rc, cc);
}