#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<int>minTree;
vector<int>maxTree;
vector<int>arr;
int n,m,a,b;
//세그먼트트리 세 번째 연습문제

int initMin(int node, int start, int end){
    if(start==end)return minTree[node]=arr[start];
    return minTree[node]=min(initMin(node*2, start, (start+end)/2), initMin(node*2+1, (start+end)/2+1, end));
}
int initMax(int node, int start, int end){
    if(start==end)return maxTree[node]=arr[start];
    return maxTree[node]=max(initMax(node*2, start, (start+end)/2), initMax(node*2+1, (start+end)/2+1, end));
}
int findMin(int node, int start, int end, int left, int right){
    if(right<start || end<left)return INT_MAX;
    if(left <= start && end <= right)return minTree[node];

    return min(findMin(node*2, start, (start+end)/2, left, right), findMin(node*2+1, (start+end)/2+1, end, left, right));
}
int findMax(int node, int start, int end, int left, int right){
    if(right<start || end<left)return 0;
    if(left <= start && end <= right)return maxTree[node];

    return max(findMax(node*2, start, (start+end)/2, left, right), findMax(node*2+1, (start+end)/2+1, end, left, right));
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    arr=vector<int>(n+1,0);
    minTree=vector<int>(n*4);
    maxTree=vector<int>(n*4);
    for(int i = 1; i <=n; i++)cin>>arr[i];

    initMin(1,1,n);
    initMax(1,1,n);

    for(int i = 0; i < m; i++){
        cin>>a >> b;
        cout << findMin(1,1,n,a,b) << " " << findMax(1,1,n,a,b) << "\n";
    }
}