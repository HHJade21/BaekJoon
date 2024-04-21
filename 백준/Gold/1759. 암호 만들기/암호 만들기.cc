#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int L, C;
vector<char> arr;
vector<char> ans;
bool vow[120]={0,};

void password(int now, int depth, int conso, int vowel){
    if(depth < L){
        for(int i = now+1; i <= C-L+depth; i++){
            if(vow[arr[i]]) {
                ans.push_back(arr[i]);
                password(i, depth+1, conso, vowel+1);
                ans.pop_back();
            }
            else {
                ans.push_back(arr[i]);
                password(i, depth+1, conso+1, vowel);
                ans.pop_back();
            }
        }
    }
    else if(conso > 1 && vowel > 0){
        for(auto i : ans) cout << i;
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    vow['a']=true;
    vow['e']=true;
    vow['i']=true;
    vow['o']=true;
    vow['u']=true;

    cin >> L >> C;
    arr=vector<char>(C);
    for(int i = 0; i < C; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    password(-1, 0, 0, 0);
}