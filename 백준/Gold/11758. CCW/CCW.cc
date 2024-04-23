#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int ccw = (x1*y2+x2*y3+x3*y1 - x2*y1 - x3*y2 - x1*y3)/2;
    if(ccw > 0)cout << 1;
    else if(ccw<0)cout<<-1;
    else cout << 0;
}