#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

bool cmp(pair<string, int>a, pair<string, int>b){
    return a.second<b.second;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;

    cin >> t;
    cin.ignore();
    while(t--){
        multimap<string,int> ms;
        string s;
        getline(cin, s);
        string tmp="";
        int cnt = 0;
        for(int i = 0; s[i]; i++){
            if(s[i]==' '){
                ms.insert({tmp,cnt++});
                tmp="";
                continue;
            }
            tmp+=s[i];
        }
        ms.insert({tmp,cnt});

        string cmd;
        cin.ignore();
        getline(cin, cmd);
        while(cmd != "what does the fox say?"){
            tmp = "";
            int space=0;
            for(int j = 0;cmd[j];j++){
                if(space>=2)tmp+=cmd[j];
                else if(cmd[j]==' ')space++;
            }
            auto it = ms.begin();
            while(ms.find(tmp) != ms.end()){
                it = ms.find(tmp);
                ms.erase(it);
            }
            getline(cin, cmd);
        }

        vector<pair<string,int>> wolfSound;

        while(ms.size()){
            auto it = ms.begin();
            wolfSound.push_back({it->first, it->second});
            ms.erase(it);
        }

        sort(wolfSound.begin(), wolfSound.end(), cmp);

        for(auto i : wolfSound)cout << i.first << " ";
        cout << "\n";
    }
}