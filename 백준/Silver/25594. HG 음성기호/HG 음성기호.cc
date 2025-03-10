#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string s, ans="";
    vector<string>hg={"aespa", "baekjoon", "cau", "debug", "edge", "firefox", "golang", "haegang", "iu", "java", "kotlin", "lol", "mips", "null", "os", "python", "query", "roka", "solvedac", "tod", "unix", "virus", "whale", "xcode","yahoo","zebra"};
    cin>>s;
    int i=0;
    while(i<s.size()){
        bool find = false;
        for(int j = 0; j < 26; j++){//hg의 모든 문자열 j와 비교
            for(int k = 0; k<hg[j].size();k++){
                if(i+hg[j].size() > s.size())continue;
                if(s[i+k]!=hg[j][k])break;
                if(k==hg[j].size()-1){
                    find=true;
                    i+=hg[j].size();
                    ans+='a'+j;
                }
            }
            if(find)break;
        }
        if(!find){
            cout<<"ERROR!";
            return 0;
        }
    }
    cout << "It's HG!\n" << ans;
}