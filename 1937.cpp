#include <stdio.h>

int n;
int g[505][505];
int d[505][505];
int dr[]={1, 0, -1, 0};
int dc[]={0, 1, 0, -1};

int max(int a, int b)
{
    return a > b ? a : b;
}

int go(int r, int c)
{
    int i, ret=1;
    
    if(d[r][c]) return d[r][c];

    for(i=0; i<4; i++) {
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(g[r][c] < g[nr][nc]) {
            ret = max(ret, go(nr, nc)+1);
        }
    }
    return d[r][c] = ret;
}

int main()
{
    int i, j, ans = 0;
    scanf("%d", &n);

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &g[i][j]);

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            ans = max(ans, go(i, j));
    printf("%d\n", ans);
    return 0;
}
