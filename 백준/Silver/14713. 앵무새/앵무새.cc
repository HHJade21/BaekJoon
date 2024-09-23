#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

queue<string> angmus[101];

void sliceString(string s, int idx){
    string tmp = "";

    for(int i = 0; i < s.size(); i++){
        if(s[i]==' '){
            angmus[idx].push(tmp);
            tmp="";
        }
        else{
            tmp+=s[i];
        }
    }
    angmus[idx].push(tmp);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    bool clear = true;
    string tmp, cest;

    cin >> n;

    cin.ignore();

    for(int i = 0; i <= n; i++){
        getline(cin, tmp);
        sliceString(tmp, i);

        //test code
        //cout << "angmu[" << i << "] : " << angmus[i].size() << "\n";
    }

    while(!angmus[n].empty()){
        bool find = false;
        for(int i = 0; i < n; i++){
            if(angmus[i].empty())continue;
            if(angmus[n].front() == angmus[i].front()){
                //test code
                //cout << i << " angmu has " << angmus[i].front() << ".\n";
                angmus[n].pop();
                angmus[i].pop();
                find = true;
                break;
            }
        }
        if(!find){
            //test code
            //cout << "break! angmus[n].size : " << angmus[n].size() << "\n";
            break;
        }
    }

    for(int i = 0; i < n; i++){
        if(!angmus[i].empty())clear=false;
    }

    if(clear && angmus[n].empty())cout<<"Possible";
    else cout<<"Impossible";
}