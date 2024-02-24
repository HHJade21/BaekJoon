#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &order, int& searchOrder, int now) {
	int temp = 0;
	for (int i = 0; i < graph[now].size(); i++) {
		temp = graph[now][i];
		if (!visited[temp]) {
			visited[temp] = 1;
			order[temp] = searchOrder++;
			dfs(graph, visited, order, searchOrder, temp);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, start, firstNode, secondNode, searchOrder = 1;
	cin >> n >> m >> start;
	vector<vector<int>> graph(n);
	vector<bool> visited(n, false);
	vector<int> order(n, 0);
	visited[start - 1] = true;
	order[start - 1] = searchOrder++;


	for (int i = 0; i < m; i++) {
		cin >> firstNode >> secondNode;
		graph[firstNode - 1].push_back(secondNode - 1);
		graph[secondNode - 1].push_back(firstNode - 1);
	}

	for (int i = 0; i < n; i++) {
		sort(graph[i].begin(), graph[i].end());
		//cout << "graph[" << i << "] is : ";
		//for (int j = 0; j < graph[i].size(); j++) {
		//	cout << graph[i][j] << " ";
		//}
		//cout << "\n";
	}


	dfs(graph, visited, order, searchOrder, start - 1);

	for (int i = 0; i < n; i++) {
		cout << order[i] << "\n";
	}
}