#include <stdio.h>
#include <string.h>

int g[505][505];
int d[505][505];

int max(int a, int b)
{
    return a > b ? a : b;
}

int go(int n, int k)
{
    int L, R;
    if(n == 0 || k == 0) return 0;

    if(d[n][k] != -1) return d[n][k];

    L = go(n-1, k-1);
    R = go(n-1, k);
    return d[n][k] = g[n][k] + max(L, R);
}

int main()
{
    int i, j, n;
    int ans=0;
    scanf("%d", &n);

    for(i=1; i<=n; i++) 
        for(j=1; j<=i; j++) 
            scanf("%d", &g[i][j]);

    memset(d, -1, sizeof(d));

    for(i=1; i<=n; i++)
        ans = max(ans, go(n, i));
    printf("%d\n", ans);

    return 0;
}
