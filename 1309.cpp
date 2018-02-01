#include <stdio.h>
#define MOD 9901

int d[100001][3];

int go(int n, int k)
{
    int a, b;
    if(n == 0) return 1;
    if(d[n][k]) return d[n][k];

    a = go(n-1, (k+1)%3);
    b = go(n-1, (k+2)%3);
    
    if(k == 0) a += go(n-1, 0);

    return d[n][k] = (a+b)%MOD; 
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", go(n, 0));
    return 0;
}
