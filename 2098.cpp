#include <stdio.h>

int n;
int g[20][20];
int d[16][1<<16];

int min(int a, int b)
{
    return a < b ? a : b;
}

int tsp(int cur, int status)
{
    int *ret = &d[cur][status];
    if(status == (1<<n)-1) {
        if(g[cur][0]) return g[cur][0];
        return 1e9;
    }
    if(*ret) return *ret;
    
    *ret = 1e9;
    for(int i=0; i<n; i++) {
        if(!(status & (1<<i)) && g[cur][i])
            *ret = min(*ret, tsp(i, status|(1<<i))+g[cur][i]);
    }
    return *ret;
}

int main()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            scanf("%d", &g[i][j]);
    }

    printf("%d\n", tsp(0, 1)); 
    return 0;
}
