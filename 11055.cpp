#include <stdio.h>

int n;
int a[1001], d[1001];

int max(int a, int b)
{
    return a > b ? a : b;
}

int lis(int s)
{
    int *ret = &d[s];
    if(s == n-1) return a[s];
    if(*ret) return *ret;

    *ret = a[s];
    for(int i=s+1; i<n; i++) {
        if(a[s] < a[i])
            *ret = max(*ret, a[s]+lis(i));
    }
    return *ret;
}

int main()
{
    int ans=0;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", a+i);

    for(int i=0; i<n; i++)
        ans = max(ans, lis(i));
    printf("%d\n", ans); 
    return 0;
}
