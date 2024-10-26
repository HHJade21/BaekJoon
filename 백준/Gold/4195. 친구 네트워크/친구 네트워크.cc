#include<iostream>
#include<map>
using namespace std;
//union-find 실습 문제
//string으로 탐색하고 집합의 크기 구하기


struct profile { //sns계정의 이름을 제외한 부가 정보
	string parent; //부모계정의 이름(find함수를 거친 후에는 루트계정의 이름)
	int count;//연결된 친구의 수. 최종적으로 출력하는건 루트 계정의 count고 나머지는 그냥 합산하는 용도. 
};

string findP(map<string, profile>& sns, string x) { //parent 찾기
	auto temp = sns.find(x); //x의 iterator 미리 저장해두고
	if (temp->second.parent == x) //자기자신이 루트면 return
		return x;
	temp->second.parent = findP(sns, temp->second.parent); //아니면 루트를 찾을때까지 재귀하며 전부 부모를 루트로 바꿔주고
	return temp->second.parent; // parent에 루트가 저장되었을테니 이를 반환하며 find함수 종료

}

//parent가 다르면 합쳐주고, parent에 count합산해주기. 
void unionP(map<string, profile>& sns, string x, string y) {
	string px = findP(sns, x);//x의 루트 계정 이름을 px에 저장
	string py = findP(sns, y);//y도

	auto t1 = sns.find(px); //루트 계정들의 iterator 미리 찾아두기
	auto t2 = sns.find(py);

	if (px == py) { //만약 두 계정의 루트가 같다면 합칠필요 없으므로
		cout << t1->second.count << "\n"; //해당 네트워크의 친구수 출력하고
		return; //union 바로 종료
	}

	//만약 서로 연결되지 않은 네트워크였다면 합쳐주기
	t2->second.parent = px; //x의 루트 계정을 y의 루트계정으로 바꾸기
	t1->second.count += t2->second.count; //최종 루트계정이 된 px의 count에 py의 count 합산

	cout << t1->second.count << "\n"; //해당 네트워크의 친구 수 출력
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, f; //테스트케이스, 테스트케이스 별 친구관계의 수
	string a, b; //테스트케이스마다 f회 계정 이름 받을 문자열들
	map<string, profile> sns; //여기에 모든 계정 정보 저장

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> f;
		sns.clear(); //테스트케이스마다 sns 초기화해주고
		for (int j = 0; j < f; j++) {
			cin >> a >> b;

			//a, b중 처음 등록된 계정이 있으면 sns map에 추가해주기
			if (sns.find(a) == sns.end()) {
				sns.insert({ a, {a, 1} });
			}
			if (sns.find(b) == sns.end()) {
				sns.insert({ b, {b, 1} });
			}


			//두 계정의 친구 네트워크를 확인하고 친구 수 출력하는 함수
			unionP(sns, a, b);
		}
	}

}