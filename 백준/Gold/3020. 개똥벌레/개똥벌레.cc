#include<stdio.h> 
int bot[500001]={0,}, top[500001]={0,};//석순과 종유석의 길이들을 카운트할 배열

int main(){
    int n, height, tmp, ans=200000, cnt = 0;
    scanf("%d %d", &n, &height);
    for(int i = 0; i < n/2; i++){
        scanf("%d", &tmp);//석순 길이 입력받고
        bot[tmp]++;//카운트
        scanf("%d", &tmp);//종유석 길이 입력받고
        top[tmp]++;//카운트
    }

    int suk = n/2;
    int jong = 0;
    for(int i = 0; i < height; i++){//바닥부터 천장까지
        //각 높이에서 통과했을 때 파괴되는 장애물의 수를 구한다.
        tmp = suk + jong;
        //최소값이면 갱신
        if(tmp < ans){
            ans = tmp;
            cnt = 1;//최소값 구간의 수 초기화
        }
        else if(tmp==ans)cnt++;//최소값과 같으면 구간의 수 증가
        
        //이제 다음 높이에서 통과했을 때 파괴될 석순과 종유석의 개수를 조정한다.
        //현재 층까지만 자라있는 석순들은 다음 층부터 안 파괴될테니 빼준다.
        suk -= bot[i];
        //다음 층에서 파괴하게 될 종유석들을 더해준다.
        jong += top[height - i];
    }

    printf("%d %d", ans, cnt);//답 출력
}