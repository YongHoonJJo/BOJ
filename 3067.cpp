#include <stdio.h>
#include <memory.h>

int coins[21];
int d[21][10001];

int coin(int n, int m)
{
    int ret;
    if(n == 0) return m%coins[0]==0; 
    if(m == 0) return 1;
    if(m < 0) return 0;
    if(d[n][m] != -1) return d[n][m];

    ret = coin(n, m-coins[n]);
    ret += coin(n-1, m);
    return d[n][m] = ret;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n, m;
        scanf("%d", &n);

        for(int i=0; i<n; i++) 
            scanf("%d", coins+i);

        scanf("%d", &m);

        memset(d, -1, sizeof(d));

        printf("%d\n", coin(n-1, m));
    }
    return 0;
}
