#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    queue<int>mine;
    int l, ml, mk, c,tmp,zombie,dmg;
    cin>>l>>ml>>mk>>c;
    for(int i = 1; i <= l; i++){
        cin>>zombie;
        if(zombie==0)continue;
        while(mine.size() && i - mine.front() >= ml){
            mine.pop();
        }
        dmg = (min(ml,i)-mine.size())*mk;
        if(zombie > dmg){
            if(!c){
                cout<< "NO";
                return 0;
            }
            else{
                c--;
                mine.push(i);
            } 
        }
    }
    cout << "YES";
}