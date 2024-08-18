#include<iostream>
#include<deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,tmp, now, next, order;
    cin >> n;
    deque<pair<int,int>> b;

    for(int i = 1; i <= n; i++){
        cin>>tmp;
        b.push_back({tmp,i});
    }

    now = b.front().first;
    cout<<1 << " ";
    b.pop_front();
    for(int i = 2; i <= n; i++){
        if(now>=0){
            for(int j = 0; j < now;j++){
                next = b.front().first;
                order = b.front().second;
                b.push_back({b.front().first, b.front().second});
                b.pop_front();
            }
            b.pop_back();
            cout << order << " ";
        }
        else{
            for(int j = 0; j < -now; j++){
                next = b.back().first;
                order = b.back().second;
                b.push_front({b.back().first, b.back().second});
                b.pop_back();
            }
            b.pop_front();
            cout << order << " ";
        }
        now = next;
    }
}