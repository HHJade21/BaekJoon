#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, a, sum = 0, max = 0, maxIdx=0, check = 0;
    cin >> n;   
    vector<int> p(n);


    int count[8001] = {0, };
    for(int i = 0; i < n; i++){
        cin >> p[i];
        sum += p[i];
        count[p[i] + 4000]++; //-4000을 count[0]에다 저장한다. 
    }

    for(int i = 0; i < 8001; i++){
        if(count[i] >= max){
            max = count[i]; //가장 많이 나오는 수가 몇 번 나오는지를 max에 저장한다.
            maxIdx=i-4000;
        }
    }
    for(int i = 0; i <=8000; i++){
        if(count[i] == max){ //i = 8000(사실 4000)부터 탐색. 최빈값이 나오는 수와 같은 빈도수로 나오는 수일때, check를 1 늘린다.
            check++;
            if(check == 2){ //그 check가 2가 된다면(최빈값 중 두 번째로 작으면)
                maxIdx = i - 4000; //i - 4000을 해서 max에 저장하고
                break; //break를 한다.
            }
        }
    }


    sort(p.begin(), p.end());
    double avg = (double)sum / (double)n;
    avg=round(avg);
    int mid = p[n / 2];
    int range = p[n-1] - p[0];
    cout << (int)avg << "\n";
    cout << mid << "\n";
    cout << maxIdx << "\n";
    cout << p[n-1] - p[0] << "\n";
    return 0;
}