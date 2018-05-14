#include <cstdio>
#include <algorithm>
using namespace std;

int a[101], b[101];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", a+i);
    for(int i=0; i<n; i++)
        scanf("%d", b+i);

    sort(a, a+n);
    sort(b, b+n, cmp);
    
    int ans=0;
    for(int i=0; i<n; i++)
        ans += (a[i]*b[i]);
    printf("%d\n", ans); 
    return 0;
}
