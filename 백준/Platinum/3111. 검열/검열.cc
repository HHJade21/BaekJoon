#include<iostream>
using namespace std;
int l=0,r,s_size,b_size;
string s,b,sl="",sr="";

bool lBomb(){
    for(int i = 0; i < b_size; i++){
        if(sl[sl.size()-1-i] != b[b_size-1-i])return false;
    }
    return true;
}
bool rBomb(){
    for(int i = 0; i < b_size; i++){
        if(sr[sr.size()-1-i] != b[i])return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>b>>s;
    r=s.size()-1;
    b_size=b.size();
    while(l<=r){
        while(l<=r){
            sl += s[l++];
            if(sl.size() >= b_size && sl[sl.size()-1] == b[b_size-1] && lBomb()){
                sl.erase(sl.end()-b_size, sl.end());
                break;
            }
        }
        while(l<=r){
            sr += s[r--];
            if(sr.size()>=b_size && sr[sr.size()-1]==b[0] && rBomb()){
                sr.erase(sr.end()-b_size, sr.end());
                break;
            }
        }
    }
    for(int i = 0; i < sr.size(); i++){
        sl += sr[sr.size()-1-i];
        if(sl.size() >= b_size && sl[sl.size()-1] == b[b_size-1] && lBomb()){
            sl.erase(sl.end()-b_size, sl.end());
        }
    }
    cout<<sl;
}