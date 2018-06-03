#include <stdio.h>

int main()
{
    int n, ans=0, idx=0;
    int k[7]={64, 32, 16, 8, 4, 2, 1};
    scanf("%d", &n);

    while(n) {
        if(n >= k[idx]) {
            ans++;
            n -= k[idx];
        }
        else
            idx++;
    }

    printf("%d\n", ans);
    return 0;
}
