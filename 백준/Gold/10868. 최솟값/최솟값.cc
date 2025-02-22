#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
//세그먼트트리 두 번째 연습문제 : 구간합이 아닌, 구간 내 최솟값을 찾아주는 코드.
vector<int>arr;
vector<int>minTree;
int n,m,tmp,a,b;

int init(int node, int start, int end){//최솟값 세그먼트트리 초기화
    if(start==end) return minTree[node]=arr[start];
    return minTree[node]=min(init(node*2, start, (start+end)/2), init(node*2+1, (start+end)/2+1, end));
}

int findMin(int node, int start, int end, int left, int right){
    if(right<start || end < left)return INT_MAX;
    if(left <= start && end <= right)return minTree[node];
    
    //여기서 반환할때 minTree[node]를 갱신한 후 반환하는 바람에 계속 틀렸음!!
    return min(findMin(node*2, start, (start+end)/2, left, right), findMin(node*2+1, (start+end)/2+1, end, left, right));
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    arr=vector<int>(n+1);
    minTree=vector<int>(n*4,INT_MAX);
    for(int i = 1 ; i <= n; i++){
        cin>>arr[i];
    }
    init(1,1,n);

    for(int i = 0; i < m; i++){
        cin>>a>>b;
        cout << findMin(1,1,n,a,b)<<"\n";
    }
}