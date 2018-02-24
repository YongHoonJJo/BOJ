#include <stdio.h>

int p[1000001], r[1000001], in[1000001];

int go(int n, int a[], int aIdx, int ck[], int ckIdx)
{
    int i;
    for(i=0; i<n; i++)
        if(a[(aIdx+i)%n] != ck[(ckIdx+i)%n])
            return 0;
    return 1;
}

int main()
{
    int i, n;
    int inIdx;

    scanf("%d", &n);
   
    for(i=0; i<n; i++) {
        int k;
        scanf("%d", &k);
        p[i] = r[n-1-i] = k;
    }

    for(i=0; i<n; i++)
        scanf("%d", in+i);

    while(in[inIdx] != p[0]) inIdx++;

    go(n, p, 0, in, inIdx) || go(n, r, n-1, in, inIdx) ? puts("good puzzle") : puts("bad puzzle"); 
    return 0;
}
