#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int value;
    int index;
};
struct cmp{
    bool operator()(const node& s1, const node& s2){
        return s1.value > s2.value;
    }
};
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, l, temp;
    cin >> n >> l;
    vector<int> arr(n);
    priority_queue<node, vector<node>, cmp> pq;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        pq.push({arr[i], i});
        while(pq.top().index < i-l+1){
            pq.pop();
        }
        cout << pq.top().value << " ";
    }
}