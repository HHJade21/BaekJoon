#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

bool cmp(pair<int,int>a, pair<int,int>b){
    return a.first<b.first;
}

struct comp{
    bool operator()(pair<int,int>a, pair<int,int>b){
        return a.second<b.second;//가격 우선 정렬
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,k,m,v;
    long long ans=0;
    cin >> n >> k;
    vector<pair<int,int>> jewel(n);//보석 무게, 가격
    vector<int>bag(k);//가방 무게

    for(int i = 0; i < n; i++){
        cin >> m >> v;
        jewel[i].first=m;//무게
        jewel[i].second=v;//가격
    }

    for(int i = 0; i < k; i++){
        cin >> bag[i];
    }

    sort(jewel.begin(), jewel.end(),cmp);//보석 무게 오름차순 정렬
    sort(bag.begin(), bag.end());//가방 무게 오름차순 정렬
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;//가격 우선순위 큐

    int ji = 0;//보석 인덱스
    for(int i = 0; i < k; i++){//각 가방에 대해
        while(ji<jewel.size() && jewel[ji].first <= bag[i]){//현재 가방에 넣을 수 있는 모든 보석을
            pq.push(jewel[ji++]);//pq에 넣고
        }

        if(!pq.empty()){//pq가 비어있지 않으면
            ans+=pq.top().second;//ans에 가장 무거운 보석의 가격을 더하고
            pq.pop();//해당 보석을 pq에서 뺀다
        }
    }

    cout << ans;
}