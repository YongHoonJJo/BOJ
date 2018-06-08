#include <stdio.h>

int r, c;
int k, v, kCnt, vCnt;
char g[251][251];

int di[]={1, 0, -1, 0};
int dj[]={0, 1, 0, -1};

int safe(int i, int j)
{
    return (0 <= i && i < r) && (0 <= j && j < c);
}

void dfs(int i, int j)
{
    if(g[i][j] == 'v') vCnt++;
    else if(g[i][j] == 'k') kCnt++;
    g[i][j] = '#';

    for(int k=0; k<4; k++) {
        int ni = i+di[k];
        int nj = j+dj[k];
        if(safe(ni, nj) && g[ni][nj] != '#')
            dfs(ni, nj);
    }
}

int main()
{
    scanf("%d%d", &r, &c);

    for(int i=0; i<r; i++)
        scanf("%s", g[i]);

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(g[i][j] != '#') {
                kCnt = vCnt = 0;
                dfs(i, j);
                if(kCnt > vCnt) k += kCnt;
                else v += vCnt;
            }
        }
    }
    printf("%d %d\n", k, v); 
    return 0;
}
