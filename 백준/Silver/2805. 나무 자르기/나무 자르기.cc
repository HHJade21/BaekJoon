#include<iostream>
#include<vector>
using namespace std;


//절단된 나무의 높이 합을 구하는 함수
long long cut(vector<int>& woods, int height) {
	long long sum = 0;
	for (int i = 0; i < woods.size(); i++) {
		if(woods[i] > height)
			sum += woods[i] - height;
	}
	return sum;
}


//나무의 수는 최대 100만이고 나무의 길이는 최대 20억, 톱의 높이는 최대 10억.
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, height; //나무의 수
	long long M, max = 0, min = 0, sum; // 상근이한테 필요한 나무의 총 길이, 탐색범위

	cin >> N >> M;

	vector<int> woods(N);

	for (int i = 0; i < N; i++) {
		cin >> woods[i];
		if (woods[i] > max)
			max = woods[i];
	}

	max++;


	//높이가 너무 작으면 sum이 M보다 크게 나온다. 반대로 너무 높으면 sum이 M보다 작게 나온다. 
	//check(min) != check(max)가 유지되려면 sum>=M, sum<M으로 min과 max의 조건식을 설정
	while (min + 1 < max) {
		height = (min + max) / 2;
		sum = cut(woods, height);
		if (sum >= M)
			min = height;
		else if (sum < M)
			max = height;
	}

	cout << min;

}