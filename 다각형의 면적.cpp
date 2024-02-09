#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    long double sum = 0, x1, y1, x2, y2, a, b;
    cin >> n;
    vector<pair<long double, long double>> p(n);
    cin >> p[0].first >> p[0].second;
    for(int i = 1; i <= n; i++){
        cin >> p[i].first >> p[i].second;
        sum += p[i-1].first * p[i%n].second - p[i-1].second * p[i%n].first;
    }
    sum/=2;

    sum = round(10*sum)/10;
    cout << fixed;
    cout.precision(1);
    cout << abs(sum);
}