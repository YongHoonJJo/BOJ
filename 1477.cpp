#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, l;
int a[101];

bool bs(int mid)
{
    int cnt=0;
    for(int i=1; i<n+2; i++) {
        int gap = a[i]-a[i-1];
        cnt += ((gap-1)/mid);
    }
    return cnt <= m;
}

int main()
{
    scanf("%d%d%d", &n, &m, &l);

    for(int i=1; i<=n; i++)
        scanf("%d", a+i);

    sort(a+1, a+n+1); 
    a[n+1] = l;


    int s=1, e=10000; 
    
    while(s <= e) {
        int mid = (s+e)/2;
        if(bs(mid)) e = mid-1;
        else s = mid+1;
    }
    printf("%d\n", e+1); 
    return 0;
}
