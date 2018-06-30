#include <stdio.h>

int main()
{
    int n, m;
    int a[10001];
    int s, e;
    int sum=0, ans=0;
    scanf("%d%d", &n, &m);

    for(int i=0; i<n; i++)
        scanf("%d", a+i);

    sum = a[0];
    s=0, e=1;

    while(e < n) {
        if(sum == m) ans++;
        if(sum < m) sum += a[e++];
        else sum -= a[s++];
    }

    if(sum == m) ans++;
    while(s < n) {
        sum -= a[s++];
        if(sum == m) ans++;
    }
    
    printf("%d\n", ans);
    return 0;
}
