#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxP[1500001] = { 0, };
struct work {
    int e; //종료일
    int s; //시작일
    int p; //금액
};
bool comp(work a, work b) {
    if(a.e == b.e){
        return a.p < b.p;
    }
    return a.e < b.e;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, t1, t2; //max는 각 날짜별 최대수익을 저장하는 dp테이블.
    cin >> n;
    vector<work> w;
    for (int i = 0; i < n; i++) {//상담목록 입력
        cin >> t1 >> t2; //시작일 i, 기간 t1, 금액 t2로 입력
        w.push_back({ i + t1, i, t2 });//w에 '종료일, 시작일, 금액'형태로 저장
    }
    sort(w.begin(), w.end(), comp); //종료일 기준으로 정렬

    int day = 1, i = 0, ans = 0; //day는 1~n까지 증가. 이에 따라 day마다 최대 수익을 갱신해나간다.
    while(day <= n){
        if (i < n && day >= w[i].e) {//만약 오늘 종료되는 상담이 있다면
            ans = max(ans, maxP[w[i].s] + w[i].p); //해당 상담을 하는게 최대값인지 확인하고
            maxP[day] = ans; //최대값으로 오늘의 최대수익 갱신
            i++;//다음 상담을 확인하기 위해 w 인덱스만 증가. day는 유지(종료일 중복 가능)
        }
        else {
            day++;//day만 증가한다. 오늘은 종료된 상담이 없으니 w인덱스는 유지
            maxP[day] = ans;//어제의 최대 수익이 오늘의 최대수익이다.
        }
    }
    cout << maxP[n];
}