#include <stdio.h>

int main()
{
    int n;
    int nextL=8, nextS=1;
    long long int ansL=9LL, ansS=0LL, ans=0LL;
    long long int arrL[10], arrS[10];
    int Lidx=0, Sidx=0;
    char buf[10];
    int factL=10, factS=10;
    scanf("%d", &n); 

    for(int i=0; i<n; i++) {
        char ch;
        scanf(" %c", &ch);
        if(ch == '<') {
            if(i == n-1 && nextL == 0) arrL[Lidx++] = 0LL;
            ansL = 1LL*nextL*factL + ansL;
            arrS[Sidx++] = ansS; ansS = nextS; factS = 1;
        }
        else {
            arrL[Lidx++] = ansL; ansL = nextL; factL = 1;
            ansS = 1LL*nextS*factS + ansS;
        }
        nextL--; factL *= 10;
        nextS++; factS *= 10;
    }
    arrL[Lidx++] = ansL;
    arrS[Sidx++] = ansS;

    for(int i=0; i<Lidx; i++) 
        printf("%lld", arrL[i]);
    puts("");
    for(int i=0; i<Sidx; i++)
        printf("%lld", arrS[i]);
    puts("");

    return 0;
}
