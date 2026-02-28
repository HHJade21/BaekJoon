#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,ans=0,x;
	cin>>n;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	cin>>x;
	sort(v.begin(),v.end());
	int left=0, right = n-1;
	while(left<right){
		while(v[left]+v[right] > x)right--;
		if(left>=right)break;
		if(v[left]+v[right]==x)ans++;
		
		left++;
	}
	cout<<ans;
}