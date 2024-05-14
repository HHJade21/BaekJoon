#include <stdio.h>
int main() {
    char s[101];
    while(gets(s) != NULL) 
        printf("%s\n", s);   
    
    return 0;
}
