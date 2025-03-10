#include<iostream> 
using namespace std;

int main(){
    int i;
    bool failed=0;
    string s;
    cin>>s;

    while(i<s.size()){
        if(s[i]=='p'&&s[i+1]=='i'){
            i+=2;
            continue;
        }
        if(s[i]=='k'&&s[i+1]=='a'){
            i+=2;
            continue;
        }
        if(s[i]=='c'&&s[i+1]=='h'&&s[i+2]=='u'){
            i+=3;
            continue;
        }
        failed=true;
        break;
    }

    if(failed)cout<<"NO";
    else cout << "YES";
}