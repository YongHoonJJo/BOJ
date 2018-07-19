#include <stdio.h>

typedef long long int lli;

lli x, y;

int bs(lli mid)
{
    lli z = (y*100LL)/x;
    return z < ((y+mid)*100LL)/(x+mid);
}

int main()
{
    while(scanf("%lld%lld", &x, &y) == 2) {
        lli s=0LL, e=1e15;
        if(x == y || (y*100LL)/x == 99) { 
            puts("-1");
            continue;
        }

        while(s <= e) {
            lli mid = (s+e)>>1;
            if(bs(mid)) e = mid-1;
            else s = mid+1;
        }
        printf("%lld\n", e+1);
    }

    return 0;
}
