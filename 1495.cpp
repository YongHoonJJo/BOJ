#include <stdio.h>
#include <string.h>

int ans, ok;
int n, s, m;
int v[101];
int d[1001][101];

int max(int a, int b)
{
    return a > b ? a : b;
}

int volume(int prev, int i)
{
    int *ret = &d[prev][i]; 
    if(i == n) {
        ok = 1;
        return prev;
    }

    // *ret == -1 : Yet
    if(*ret != -1) return *ret;

    *ret = -2; // Impossible
    if(prev+v[i] <= m) *ret = max(*ret, volume(prev+v[i], i+1)); 
    if(prev-v[i] >= 0) *ret = max(*ret, volume(prev-v[i], i+1)); 

    return *ret; 
}

int main()
{
    scanf("%d%d%d", &n, &s, &m);

    for(int i=0; i<n; i++) {
        scanf("%d", v+i);
    }

    memset(d, -1, sizeof(d));

    ans = volume(s, 0); 
    if(!ok) ans = -1; 
    printf("%d\n", ans);
    return 0;
}
