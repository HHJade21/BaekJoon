#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
struct d {
    int h;
    int w;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
   
    vector<d>name(N);
    for (int i = 0; i<N; i++) {
        cin >> name[i].w >> name[i].h;
    }
    vector<int>ans(N,1);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                if (name[i].w < name[j].w && name[i].h < name[j].h) {
                    ans[i]++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
}