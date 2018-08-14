#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    while(n--) {
        int a, b;
        int ans = 1;
        scanf("%d%d", &a, &b);
        
        b = b % 4 + 4;
        while(b--)
            ans = (ans*a)%10;

        if(ans == 0) ans = 10;
        printf("%d\n", ans);
    }
    
    return 0;
}
