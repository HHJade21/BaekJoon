#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, temp1, temp2, count = 0;

	int map[100] = { 0, }; //1~이면 snake, 16~면 ladder
	bool visited[100] = { false, }; //방문확인 배열
	queue<int> bfsQ; //너비우선탐색용 큐

	cin >> n >> m;

	for (int i = 0; i < n + m; i++) {
		cin >> temp1 >> temp2;
		map[temp1 - 1] = temp2 - 1;
	}

	visited[0] = true;
	bfsQ.push(0);

	while (!bfsQ.empty() && !visited[99]) {
		count++;
		temp2 = bfsQ.size();
		for (int k = 0; k < temp2; k++) {
			for (int i = 1; i <= 6; i++) {
				temp1 = bfsQ.front() + i;
				if (temp1 >= 100 || visited[temp1] || visited[99])
					continue;
				while (map[temp1]) { // 0이 아닌 경우, 즉 뱀이나 사다리가 있는 경우
					visited[temp1] = true;
					temp1 = map[temp1]; //목적지까지 이동
				}
				if (visited[temp1])
					continue;

				visited[temp1] = true;
				bfsQ.push(temp1);
			}
			bfsQ.pop();
		}
		
	}

	cout << count;
}