#include <stdio.h>

int n;
char g[101][101];
int visited[101][101];
int di[]={1, 0, -1, 0};
int dj[]={0, 1, 0, -1};

int safe(int i, int j)
{
    return (0 <= i && i < n) && (0 <= j && j < n);
}

void dfs(int i, int j, char color)
{
    int k;
    visited[i][j] = 1;
    for(k=0; k<4; k++) {
        int ni = i+di[k];
        int nj = j+dj[k];
        if(safe(ni, nj) && !visited[ni][nj] && g[ni][nj] == color)
            dfs(ni, nj, color);
    }
}

void go()
{
    int i, j, ans=0;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
           if(!visited[i][j]) {
                ans++;
                dfs(i, j, g[i][j]);
           }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int i, j;
    int rb=0, rgb=0;
    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%s", g[i]);

    go();
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            visited[i][j] = 0;
            if(g[i][j] == 'G')
                g[i][j] = 'R';
        }
    }
    
    go();
    return 0;
}
