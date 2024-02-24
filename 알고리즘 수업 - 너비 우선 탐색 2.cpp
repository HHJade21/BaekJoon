#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool comp(int a, int b) {
	return (a > b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, start, dest, t1, t2, size, now, nowSize, newNode, count = 1;
	cin >> n >> m >> start;
	start--;
	queue<int> bfsQ;
	bfsQ.push(start);
	vector<int> visited(n, 0);
	visited[start] = 1;
	vector<vector<int>> graph(n, vector<int>());

	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		t1--;
		t2--;
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}

	for (int i = 0; i < n; i++) {
		sort(graph[i].begin(), graph[i].end(), comp);
	}

	while (!bfsQ.empty()) {
		size = bfsQ.size();
		for (int i = 0; i < size; i++) {
			now = bfsQ.front();
			nowSize = graph[now].size();
			for (int j = 0; j < nowSize; j++) {
				newNode = graph[now][j];
				if (!visited[newNode]) {
					bfsQ.push(newNode);
					visited[newNode] = ++count;
				}
			}
			bfsQ.pop();
		}
	}

	for (int i = 0; i < n; i++) {
		cout << visited[i] << "\n";
	}
}