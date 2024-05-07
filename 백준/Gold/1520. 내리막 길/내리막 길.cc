#include<iostream>
using namespace std;
int arr[503][503] = { 0, };
int dp[503][503];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;
int go(int i, int j)
{

	if (i == n - 1 && j == m - 1)
	{
		
		return 1;
	}
	if (dp[i][j] > -1)
	{
		
		return dp[i][j];
	}
	//방문 표시
		
		dp[i][j] = 0;
		for (int k = 0; k < 4; k++)
		{
			int nx = dx[k] + i;
			int ny = dy[k] + j;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				
				if (arr[nx][ny] < arr[i][j])
				{
					
					dp[i][j] += go(nx, ny);
				}
			}
		}
	

	return dp[i][j];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	cin >> n >> m;
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	
	cout << go(0, 0);
	return 0;
}