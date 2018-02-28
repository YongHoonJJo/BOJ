#include <stdio.h>

int n, ans=1e9;
int g[21][21];
int start[11], link[11];

int min(int a, int b)
{
    return a < b ? a : b;
}

int abs(int k)
{
    return k > 0 ? k : -k;
}

void go(int k, int ti, int ki)
{
    if(ti == n/2 || ki == n/2) {
        int S=0, L=0;
        if(ti == n/2) {
            while(k)
                link[ki++] = k--;
        }
        if(ki == n/2) {
            while(k)
                start[ti++] = k--;
        }
        
        for(int i=0; i<ki; i++) {
            for(int j=i+1; j<ki; j++) {
                S += (g[start[i]][start[j]] + g[start[j]][start[i]]);
                L += (g[link[i]][link[j]] + g[link[j]][link[i]]);
            }
        }
        ans = min(ans, abs(S-L));
        return ;
    }

    start[ti] = k;
    go(k-1, ti+1, ki);

    link[ki] = k;
    go(k-1, ti, ki+1);
}

int main()
{
    int i, j;
    scanf("%d", &n);

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &g[i][j]);

    go(n, 0, 0); 
    printf("%d\n", ans);
    return 0;
}
