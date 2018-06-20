#include <stdio.h>

int a[20001];
long long d[21001];
int n, m, k;

long long min(long long a, long long b)
{
    return a < b ? a : b;
}

long long orange(int s, int e)
{
    long long *ret = &d[s];
    int size, big=0, small=0x7fffffff;
    long long box;

    if(s >= e) return 0;
    if(*ret != -1) return *ret;

    *ret = 0x7fffffffffffffff;
    size = m < e-s+1 ? m : e-s+1;
    for(int i=0; i<size; i++) {
        if(big < a[s+i]) big = a[s+i];
        if(small > a[s+i]) small = a[s+i];
        box = 1LL*(i+1)*(big-small) + k;
        *ret = min(*ret, box+orange(s+i+1, e));
    }
    return *ret;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for(int i=0; i<n; i++) {
        scanf("%d", a+i);
        d[i] = -1;
    }

    printf("%lld\n", orange(0, n));
    return 0;
}
