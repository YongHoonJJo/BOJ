#include <stdio.h>
#define INF 0x3f3f3f3f

int d[1000001];

int go(int n)
{
    int a, b, c, ans;
    a = b = c = INF;
    if(n == 1) return 0;
    if(d[n]) return d[n];

    if(n%3 == 0) a = go(n/3)+1;
    if(n%2 == 0) b = go(n/2)+1;
    c = go(n-1)+1;
    ans = a < b ? a : b;
    ans = ans < c ? ans : c;
    return d[n] = ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", go(n));
    return 0;
}
