#include<stdio.h>


int main(){
    char taebo[1001];
    scanf("%s",taebo);

    int idx=0,left=0, right=0;

    while(taebo[idx]!='0'){
        if(taebo[idx]=='@')left++;
        idx++;
    }

    while(taebo[idx]!='\0'){
        if(taebo[idx]=='@')right++;
        idx++;
    }

    printf("%d %d", left, right);
}
