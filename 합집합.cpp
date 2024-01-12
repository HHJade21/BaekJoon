#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct rect{
    long long x;
    long long y;
};

bool comp(rect a, rect b){
    if(a.y == b.y)
        return a.x >= b.x;
    else
        return a.y > b.y;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n, s, w = 0, a, b;
    long long sum = 0;
    cin >> n;
    vector<rect> r(n);
    for(int i = 0 ; i < n; i++){
        cin >> a >> b;
        r[i].x = a/2;
        r[i].y = b/2;
    }

    sort(r.begin(), r.end(), comp);

    sum += r[0].x*r[0].y;
    w = r[0].x;

    for(int i = 1; i < n; i++){
        if(r[i].y != r[i-1].y && r[i].x > w){
            sum += r[i].y * (r[i].x - w);
            w = r[i].x;
        }
    }

    cout << sum*4;
}