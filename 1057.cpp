#include <stdio.h>

int main()
{
    int n, a, b;
    int ans=0;
    scanf("%d%d%d", &n, &a, &b);

    while(1) {
        ans++;
        if(a&1) a++;
        if(b&1) b++;
        if(a == b) break;
        a >>= 1; 
        b >>= 1;
    }
    printf("%d\n", ans);
    return 0;
}
