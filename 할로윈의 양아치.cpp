#include<iostream>
#include<vector>
using namespace std;
int n, m, k, t1, t2;
struct a{
    int candy;
    int p;//집합 인덱스(자기자신으로 초기화)
    int size;//집합 규모
};
vector<a> kids(30001);
vector<pair<int, int>> kids2; //first는 집합 사탕수, second는 집합 규모

int find(int a){
    if(kids[a].p == a)
        return a;
    else{
        return kids[a].p = find(kids[kids[a].p].p);
    }
}

void union_find(int a, int b){
    int p1, p2;
    p1 = find(a);
    p2 = find(b);
    if(p1 != p2){
        kids[p2].candy += kids[p1].candy;
        kids[p2].size += kids[p1].size;
        kids[p1].p = p2;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> k; //아이의 수, 친구관계의 수, 공명조건
    for(int i = 1; i <= n; i++){
        cin >> kids[i].candy;//i번째 아이가 가진 사탕 수 입력
        kids[i].p = i; //union-find를 위해 자기자신을 부모로 초기화
        kids[i].size = 1;
    }
    for(int i = 0; i < m; i++){
        cin >> t1 >> t2; //친구관계가 입력되면
        union_find(t1, t2);
    }
    for(int i = 1; i <= n; i++){
        if(kids[i].p == i){
            kids2.push_back({kids[i].candy, kids[i].size});
        }
    }
    vector<int> dp(k, 0); //냅색 dp테이블
    int uc = kids2.size(), tc, tk; //친구집합의 개수, 집합 사탕수, 집합 사이즈 임시저장 변수
    for(int i = 0; i < uc; i++){
        tc = kids2[i].first; //이번에 검사할 친구집합의 총 사탕수
        tk = kids2[i].second; //이번에 검사할 친구집합의 총 인원수
        for(int j = k-1; j>= tk; j--){
            if(dp[j] < dp[j-tk] + tc){
                dp[j] = dp[j-tk] + tc;
            }
        }
    }
    cout << dp[k-1];
}