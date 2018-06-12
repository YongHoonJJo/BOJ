#include <stdio.h>

int ans, fill;
int a[210][210];
int visited[210][210];
int di[]={1, 0, -1, 0};
int dj[]={0, 1, 0, -1};

int safe(int i, int j)
{
    return (0 <= i && i < 210) && (0 <= j && j < 210);
}

void filled(int i, int j)
{
    a[i][j] = 2;

    for(int k=0; k<4; k++) {
        int ni = i+di[k];
        int nj = j+dj[k];
        if(safe(ni, nj) && !a[ni][nj])
            filled(ni, nj);
    }
}

void dfs(int i, int j)
{
    visited[i][j] = 1;
    for(int k=0; k<4; k++) {
        int ni = i+di[k];
        int nj = j+dj[k];
        if(a[ni][nj] == 2) ans++;
        if(!visited[ni][nj] && a[ni][nj] == 1)
            dfs(ni, nj);
    }
}

int main()
{
    int c, r, k;
    scanf("%d%d", &c, &r);

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            int p=1;
            scanf("%d", &k);
            if(i&1) p=0;
            if(k) a[i+1][j*2+p+1] = a[i+1][j*2+1+p+1] = 1;            
        }
    }
    
    filled(0, 0);

    for(int i=0; i<210; i++) 
        for(int j=0; j<210; j++) 
            if(!visited[i][j] && a[i][j]==1) 
                dfs(i, j);

    printf("%d\n", ans);
    return 0;
}
