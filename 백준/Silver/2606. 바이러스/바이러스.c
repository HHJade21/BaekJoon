#include <stdio.h>

int l, adj[101][101], visit[101],c;

void v(int t)
{
    int i;
    visit[t] = 1;
    for (i = 1; i <= c; i++)
    {
        if (visit[i] == 1) continue;
        if (adj[t][i] == 0) continue;
        visit[i] = 1;
        v(i);
    }
}

int main()
{
    int a, b, cnt = 0, i;
    scanf("%d", &c);
    scanf("%d", &l);
    for (i = 0; i < l; i++)
    {
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    v(1);
    for (i = 1; i <= 100; i++)
    {
        if (visit[i] == 1) cnt++;
    }
    printf("%d", cnt - 1);
}