#include<iostream>
#include<stack> 
using namespace std;
int main(){//개어렵네미친
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n,tmp,ans=0;
    cin>>n;
    stack<pair<long long,long long>>st;//{키, 같은 키인 사람의 수}순서로 저장되는 단조감소스택
    for(int i = 0; i<n; i++){
        cin>>tmp;//다음 사람의 키 입력
        while(st.size()&&st.top().first < tmp){//앞에 나보다 작은 사람들 있으면 전부 스택에서 제거
            ans += st.top().second;//근데 걔네랑 나랑 볼 수 있으니 답은 증가시켜야 함.
            st.pop();//답 증가시켰으면 빼버리기.
        }
        if(st.empty()){//스택이 비었으면 푸쉬만 하고 넘어가야 한다.(아래는 나랑 같거나 큰 애들 처리니까.)
            st.push({tmp,1});
            continue;
        }
        long long cnt=1;//tmp와 키가 같은 연속된 사람의 수
        if(st.top().first == tmp){//나랑 같은 애들이 앞에 있으면
            ans += st.top().second;//걔네랑 서로 볼 수 있다. 
            cnt = st.top().second+1;//나를 포함해서 cnt 갱신해주고
            st.pop();//일단 빼
            if(st.size())ans++;//팝 했으면 앞에 '키가 더 큰 사람'이 있는지 판별되니까 답을 증가시킬지 말지 결정.
        }        
        else ans++;//나랑 큰 애들만 앞에 있으면, 제일 뒤쪽 한 명만 나랑 볼 수 있다. 
        
        st.push({tmp,cnt});//내 정보 스택에 입력
    }
    cout<<ans;
}