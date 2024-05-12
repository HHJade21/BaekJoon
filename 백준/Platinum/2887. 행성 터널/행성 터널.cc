#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct planet{//행성 정보 저장할 배열 준비
    int idx;
    int x;
    int y;
    int z;
};
vector<planet> star;

struct node{//우선순위큐 준비
    int s;
    int e;
    int w;
};
struct cmp{
    bool operator()(node a, node b){
        return a.w>b.w;
    }
};
priority_queue<node, vector<node>,cmp> pq;

vector<int> parent;//유니온파인드 준비
int Find(int a){
    if(parent[a]==a)return a;
    else return parent[a]=Find(parent[a]);
}
void Union(int a, int b){
    int pa=Find(a), pb = Find(b);
    parent[pa]=pb;
}

bool xcmp(planet a, planet b){//행성 좌표 x,y,z기준으로 각각 정렬할 때 쓸 함수들
    return a.x<b.x;
}
bool ycmp(planet a, planet b){
    return a.y < b.y;
}
bool zcmp(planet a, planet b){
    return a.z<b.z;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, a, b, c;
    long long ans = 0;
    cin >> n;

    parent = vector<int>(n,0);//유니온파인드를 위한 부모 배열 초기화
    for(int i = 0; i < n; i++)parent[i]=i;

    for(int i = 0; i < n; i++){//행성 정보 배열 입력
        cin >> a >> b >> c;
        star.push_back({i,a,b,c});
    }

    sort(star.begin(), star.end(), xcmp);//x좌표기준 정렬
    for(int i = 1; i < n; i++) pq.push({star[i-1].idx, star[i].idx, star[i].x - star[i-1].x});//x좌표 연결비용 pq에 추가
    sort(star.begin(), star.end(), ycmp);//y좌표기준 정렬
    for(int i = 1; i < n; i++) pq.push({star[i-1].idx, star[i].idx, star[i].y - star[i-1].y});//y좌표 연결비용 pq에 추가
    sort(star.begin(), star.end(), zcmp);//z좌표기준 정렬
    for(int i = 1; i < n; i++) pq.push({star[i-1].idx, star[i].idx, star[i].z - star[i-1].z});//z좌표 연결비용 pq에 추가


    while(pq.size()){//최소신장트리 비용 구하기
        int ta = pq.top().s, tb = pq.top().e, tw = pq.top().w;//top의 정보 저장하고 pq pop
        pq.pop();
        int pa = Find(ta), pb = Find(tb);
        if(pa == pb)continue;
        Union(pa, pb);//아직 연결되어 있지 않은 행성 간의 터널이면 만들어준다
        ans+=tw;//건설비용 합산
    }

    cout << ans;
}
