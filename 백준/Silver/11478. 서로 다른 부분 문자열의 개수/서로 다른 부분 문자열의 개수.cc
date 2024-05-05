#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    set<string> a;
    string s;
    cin >> s;
    int size = s.length();
    for(int i = 1; i < size; i++){
        for(int j = 0; j <= size - i; j++){
            string t =s.substr(j, i);
            a.insert(t);
        }
    }
    cout << a.size()+1;
}