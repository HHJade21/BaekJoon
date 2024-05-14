#include <stdio.h>
#include <string.h>

int main()
{
    char s[30001];
    char code[30001];
    int ci=0;
    gets(s);
    scanf("%s",code);

    for(int i = 0; i < strlen(s); i++){
        if(s[i]>='a'&&s[i]<='z'){
            char x = s[i]-code[ci %= strlen(code)] -1 + 'a';
            if(x<'a') x+=26;
            ci++;
            printf("%c", x);
        }
        else {
            ci++;
            printf("%c", s[i]);
        }
    }
}