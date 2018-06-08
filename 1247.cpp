#include <stdio.h>

int main()
{
    int tc=3;
    while(tc--) {
        int n, pidx=0, midx=0;
        long long ans=0;
        long long p[100001];
        long long m[100001];
        scanf("%d", &n);
        
        while(n--) {
            long long k;
            scanf("%lld", &k);
            if(k > 0) p[pidx++] = k;
            else m[midx++] = k;
        }
        
        while(pidx > 0 && midx > 0) {
            if(ans > 0) ans += m[--midx];
            else ans += p[--pidx];
        }
        
        for(int i=0; i<pidx; i++) {
            ans += p[i];
            if(ans > 0) break;
        }
        
        for(int i=0; i<midx; i++) {
            ans += m[i];
            if(ans < 0) break;
        }

        if(ans == 0) puts("0");
        else ans > 0 ? puts("+") : puts("-");
    }
    return 0;
}
