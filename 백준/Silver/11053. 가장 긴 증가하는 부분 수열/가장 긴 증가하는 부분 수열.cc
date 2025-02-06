#include<iostream>
#include<vector>
using namespace std;
//가장 긴 증가하는 부분수열 == LIS

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int nums[1001] = { 0, };
    int dp[1001] = { 0, };

	int n, ans=0;
	cin >> n;

	for (int i = 1; i <= n; i++) {//전체 수열 입력
		cin >> nums[i];
	}

	for (int i = 1; i <= n; i++) {//수열의 i번째 숫자로 끝나는 LIS 찾기
		for (int j = 0; j < i; j++) {//i번째 앞쪽 숫자들 전부 확인해서
			if (nums[i] > nums[j]) {//i번째 숫자보다 작은 숫자가 발견되면 
				dp[i]=max(dp[i], dp[j]+1);//걔로 끝나는 LIS에 덧붙여서 dp[i]갱신
			}
		}
		ans = max(dp[i],ans);//최댓값 찾기
	}

	cout << ans;//LIS 길이 최댓값 출력
}