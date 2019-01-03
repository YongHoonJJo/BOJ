#include <stdio.h>

int n, k;
int x[1000005];

int bs(int t)
{
    long long cnt=0LL;
    for(int i=0; i<n; i++) {
        if(x[i] < t)
            cnt += (t-x[i]);
    }
    return cnt <= 1LL*k; 
}

int main()
{
    scanf("%d%d", &n, &k);

    int s=1e9, e=2e9;
    for(int i=0; i<n; i++) {
        scanf("%d", x+i);
        if(s > x[i])
            s = x[i];
    }
   
    while(s <= e) {
        int m = (s+e)/2;
        if(bs(m)) s = m+1;
        else e = m-1;
    }

    printf("%d\n", e);
    return 0;
}
