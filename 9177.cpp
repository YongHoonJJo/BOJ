#include <stdio.h>
#include <string.h>

int aLen, bLen;
char a[201], b[201], c[401];
int d[201][201];

int word(int aIdx, int bIdx, int cIdx)
{
    int *ret = &d[aIdx][bIdx];
    if(aIdx == aLen && bIdx == bLen) return 1;
    if(*ret != -1) return *ret;

    *ret = 0;
    if(a[aIdx] == c[cIdx]) *ret = word(aIdx+1, bIdx, cIdx+1);    
    if(*ret) return *ret;
    if(b[bIdx] == c[cIdx]) *ret = word(aIdx, bIdx+1, cIdx+1);
    return *ret;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int tc=1; tc<=n; tc++) {
        scanf("%s%s%s", a, b, c);
      
        printf("Data set %d: ", tc);
        
        aLen = strlen(a);
        bLen = strlen(b);

        memset(d, -1, sizeof(d));        
        word(0, 0, 0) ? puts("yes") : puts("no");
    }
    
    return 0;
}
