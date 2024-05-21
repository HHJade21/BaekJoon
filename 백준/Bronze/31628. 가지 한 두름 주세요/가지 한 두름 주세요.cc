#include<stdio.h>
#include<string.h>

int main(){
    char gaji[10][10][10];//행,열,문자열길이-로 구성된 3차원배열(==문자열 2차원배열)
    int clear = 1;//1이면 두름 만들기 가능, 0이면 불가능 
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            scanf("%s",gaji[i][j]);
        }
    }

    for(int i = 0; i < 10; i++){
        clear=1;
        for(int j = 1; j < 10; j++){
            if(strcmp(gaji[i][j],gaji[i][0])){//현재 행의 문자열 하나라도 다르면
                clear=0;
                break;//다음 행으로 넘어가기
            }
        }
        if(clear){//현재 행의 모든 문자열이 같으면
            printf("1");
            return 0;//1출력 후 프로그램 종료
        }
    }

    for(int i = 0; i < 10; i++){
        clear=1;
        for(int j = 1; j < 10; j++){
            if(strcmp(gaji[j][i],gaji[0][i])){//현재 열의 문자열 하나라도 다르면
                clear=0;
                break;//다음 열으로 넘어가기
            }
        }
        if(clear){//열재 열의 모든 문자열이 같으면
            printf("1");
            return 0;//1출력 후 종료
        }
    }

    printf("0");//어떤 행도 열도 한 두름을 만들 수 없으면 0출력 후 종료
    
}
