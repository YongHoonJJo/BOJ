#include <stdio.h>

int f[101];
long long d[101][21];

long long go(int i, int j)
{
    long long a, b;
    if(j < 0 || j > 20) return 0;
    if(i == 1) return f[i] == j;
    if(d[i][j]) return d[i][j];

    a = go(i-1, j+f[i]);
    b = go(i-1, j-f[i]);
    return d[i][j] = a + b;
}

int main()
{
    int i, n;
    scanf("%d", &n);

    for(i=1; i<=n; i++)
        scanf("%d", f+i);

    printf("%lld\n", go(n-1, f[n]));

    return 0;
}
