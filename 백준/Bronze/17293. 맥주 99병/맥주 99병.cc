#include<stdio.h> 
#include<string.h> 

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i = n; i >= 3; i--){
        printf("%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottles of beer on the wall.\n\n", i, i, i-1);
    }

    if(n>=2){
        printf("2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer on the wall.\n\n");
    }

    if(n>=1)
        printf("1 bottle of beer on the wall, 1 bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall.\n\n");

    if(n>1)
        printf("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, %d bottles of beer on the wall.", n);
    
    else{
        printf("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, %d bottle of beer on the wall.", n);

    }
}