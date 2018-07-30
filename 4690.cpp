#include <stdio.h>

int t(int x)
{
    return x*x*x;
}

int main()
{
    for(int a=2; a<=100; a++) {
        for(int b=2; b<=100; b++) {
            for(int c=b; c<=100; c++) {
                for(int d=c; d<=100; d++) {
                    if(t(a) == t(b)+t(c)+t(d)) 
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                }
            }
        }
    }
    
    return 0;
}
