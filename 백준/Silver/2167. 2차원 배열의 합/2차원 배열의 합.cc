#include<stdio.h>

int main(){

    int n, m;
    scanf("%d %d", &n, &m);
    int arr[301][301]={0,};
    int sum[301][301]={0,};

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        int tmp = 0;
        for(int j = 1; j <= m; j++){
            tmp+=arr[i][j];
            sum[i][j]=sum[i-1][j]+tmp;
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <=m; j++){
    //         printf("%d ", sum[i][j]);
    //     }
    //     printf("\n");
    // }


    int t, r1, c1, r2, c2;
    scanf("%d",&t);
    
    while(t--){
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        printf("%d\n", sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1]);
    }
}
