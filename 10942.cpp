#include <stdio.h>
#include <string.h>

int p[2001];
int d[2001][2001];

int isP(int s, int e)
{
    int i;
    if(s >= e) return 1;
    if(d[s][e] != -1) return d[s][e];
    if(p[s] != p[e]) return 0;
    return d[s][e] = isP(s+1, e-1);
}

int main()
{
    int i, j, n, m;
    scanf("%d", &n);

    for(i=1; i<=n; i++)
        scanf("%d", p+i);

    memset(d, -1, sizeof(d));

    scanf("%d", &m);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", isP(a, b));
    }

    return 0;
}
