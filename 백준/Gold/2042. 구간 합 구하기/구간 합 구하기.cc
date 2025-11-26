#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n,m,k;


//============새그먼트 트리
long long arr[1000001]={0}; //수의 값 저장
long long tree[4000001]={0}; //tree값 저장


//구간합 구하기
long long init(int st,int ed,int node){
	if(st==ed)return tree[node]=arr[st]; //구간합에 st~ed가 다 포함될 경우
	return tree[node]=init(st,(st+ed)/2,node*2)+init((st+ed)/2+1,ed,node*2+1); //왼쪽 자식 오른쪽 자식으로 내려가는 것
	
}

//구간합 업뎃
//st~ed: 구간 범위, node: 현재 새그먼트 트리노드, index: 수정할 값 인덱스, diff: 수정될 값과의 차
void update(int st,int ed, int node, int index,long long diff){
	if(index<st||index>ed)return; //index가 범위에 포함되지 않은경우
	tree[node]+=diff;
	//리프가 아니면 재귀
	if(st!=ed){
		update(st,(st+ed)/2,node*2,index,diff);
		update((st+ed)/2+1,ed,node*2+1,index,diff);
	}
}

//구간합 계산
//1-포함x:return 0, 2-완전히 포함:return (자기자신의 합), 3-일부포합:return (sum(왼쪽)+sum(오른쪽))
long long sum(int st,int ed, int node, int left, int right){
	//st~ed:현재 범위, node:현재노드, left~right:구할 범위
	if(left>ed||right<st)return 0; //범위에 포함 안됨
	else if(left<=st&&right>=ed)return tree[node]; //완전히 포함
	//일부만 포함
	return sum(st,(st+ed)/2,node*2,left,right)+sum((st+ed)/2+1,ed,node*2+1,left,right);

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	long long a,b,c;

	cin>>n>>m>>k;

	//숫자 값 입력
	for(int i=1;i<=n;i++)cin>>arr[i];
	init(1,n,1); //node는 1부터-새그먼트 트리 세팅

	for(int i=1;i<=m+k;i++){
		cin>>a>>b>>c;
		if(a==1){
			update(1,n,1,b,c-arr[b]);
			arr[b]=c;
		}
		else if(a==2){
			cout<<sum(1,n,1,b,c)<<"\n";
			
		}
	}

	

	return 0;
}

