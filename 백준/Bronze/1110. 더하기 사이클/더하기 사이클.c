#include <stdio.h>

int main()
{
    int n=-1 , s , a , i=0;
    scanf("%d", &a);
    s=a;
    do{
        n=s/10+s%10;
        s=(s%10)*10+n%10;
        i++;
    }while(s!=a);
    printf("%d" , i);

    return 0;
}