#include <stdio.h>

typedef long long int lli;

int n, m;
int t[100001];

int isPossible(lli mid)
{
    lli cnt=0LL;
    for(int i=0; i<n; i++) {
        cnt += (mid/t[i]);
    }
    return cnt >= m;
}

int main()
{
    lli s=1, e=1e15;
    scanf("%d%d", &n, &m);

    for(int i=0; i<n; i++) {
        scanf("%d", t+i);
    }

    while(s <= e){
        lli mid = (s+e)>>1;
        if(isPossible(mid)) e = mid-1;
        else s = mid+1;
    }
    printf("%lld\n", e+1);
    return 0;
}
