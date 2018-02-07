#include <stdio.h>

int main()
{
    int a, b;
    int x=0, y=0;
    scanf("%d%d", &a, &b);
    
    while(a) {
        x *= 10; y *= 10;
        x += a%10; a/=10;
        y += b%10; b/=10;
    }
    
    printf("%d\n", x > y ? x : y);
    
    return 0;
}
