#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int a, b, c, d, yak;
    cin >> a >> b >> c >> d;//분자,분모,분자,분모
    if(b<d){
        swap(a,c);
        swap(b,d);
    }
    int tb = b, td = d;
    while(tb%td!=0){
        tb%=td;
        swap(tb,td);
    }
    yak=td;
    int ja = a*(d/yak)+c*(b/yak), mo = b*d/yak;

    int change = 0;
    if(ja<mo){
        swap(ja, mo);
        change = 1;
    } 
    int tj = ja, tm = mo;
    while(ja%mo!=0){
        ja%=mo;
        swap(ja,mo);
    }
    yak = mo;
    
   
    if(change)swap(tj,tm);

    cout << tj/yak << " " << tm/yak;

}