#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int note[8];
    bool asc = true, des = true;
    for(int i = 0; i < 8; i++)cin>>note[i];

    for(int i = 0; i < 7; i++){
        if(note[i]>=note[i+1])asc = false;
    }
    for(int i = 0; i < 7; i++){
        if(note[i]<=note[i+1])des = false;
    }

    if(asc){
        cout << "ascending";
        return 0;
    }
    else if(des){
        cout<<"descending";
        return 0;
    }
    else{
        cout << "mixed";
        return 0;
    }

}