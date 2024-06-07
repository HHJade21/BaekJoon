#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n, r, s,Min,Max;

    cin >> n >> r >> s;

    while(n--){
        Min=50;
        Max=0;
        vector<string> s(r);
        for(int i = 0; i < r; i++){
            cin >> s[i];

            if(s[i].find("#")==string::npos)continue;

            Min=min(i,Min);
            Max=max(i,Max);
        }

        cout<< Max-Min << "\n";
    }
    
}