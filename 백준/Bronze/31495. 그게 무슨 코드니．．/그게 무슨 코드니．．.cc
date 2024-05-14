#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string s;
    getline(cin, s);
    if(s.length()>2 && s[0]=='"' && s[s.length()-1]=='"' ){
        for(int i = 1; i < s.length()-1; i++)cout<<s[i];
    }
    else cout << "CE";
}