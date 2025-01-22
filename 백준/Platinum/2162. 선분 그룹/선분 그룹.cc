#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int parent[3000],n;
int group[3000],gcnt=0;
bool chk[3000]={0,};

int Find(int x){
    if(parent[x]==x)return x;
    return parent[x]=Find(parent[x]);
}
void UnionF(int x, int y){
    x=Find(x);
    y=Find(y);
    if(x==y) return;
    
    if(x>y){
        parent[x]=y;
        group[y]+=group[x];
    }
    else{
        parent[y]=x;
        group[x]+=group[y];
    }
    
}

struct yx{
    int y;
    int x;
};

struct p{
    yx p1;
    yx p2;
};

int CCW(yx a, yx b, yx c){
    int s = a.x*b.y + b.x*c.y + c.x*a.y;
    s -= (a.y*b.x + b.y*c.x + c.y*a.x);

    if(s>0)return 1; //a,b,c는 반시계 방향
    else if(s==0)return 0;//a,b,c는 직선
    else return -1;//a,b,c는 시계방향
}

void xySort(yx& a, yx& b){
    if(a.x==b.x){
        if(a.y>b.y) swap(a,b);
    }
    else if(a.x>b.x)swap(a,b);
}

bool overlap(p a, p b){
    yx p_1 = a.p1, p_2 = a.p2, p_3 = b.p1, p_4 = b.p2;
    int p1p2 = CCW(p_1, p_2, p_3) * CCW(p_1,p_2,p_4);
    int p3p4 = CCW(p_3, p_4, p_1) * CCW(p_3,p_4,p_2);
    if(p1p2==0 && p3p4==0){
        //직선 판정 다시 짤 것.
        xySort(p_1,p_2);
        xySort(p_3,p_4);
        if(p_1.x==p_2.x) return p_3.y<=p_2.y && p_1.y<=p_4.y;
        else return p_3.x<=p_2.x && p_1.x<=p_4.x;
    }
    return (p1p2<=0 && p3p4<=0);
}

p lines[3000];

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    

    for(int i = 0; i < 3000; i++){
        parent[i]=i;
        group[i]=1;
    }

    cin >> n;

    for(int i = 0; i < n; i++){
        cin>>lines[i].p1.x>>lines[i].p1.y>>lines[i].p2.x>>lines[i].p2.y;
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(overlap(lines[i], lines[j])){
                UnionF(i,j);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(Find(i)!=i)continue;//새 그룹이 아닌 경우 패스
        //새 그룹을 발견한 경우
        gcnt++;//그룹의 개수 증가
        ans=max(ans, group[i]);
    }
    cout<<gcnt<<"\n"<<ans;
}