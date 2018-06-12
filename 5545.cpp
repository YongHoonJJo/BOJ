#include <cstdio>
#include <algorithm>
using namespace std;

int d[101];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);

    for(int i=0; i<n; i++)
        scanf("%d", d+i);

    sort(d, d+n, cmp);
    
    int cost = a;
    int cal = c;
    int ans= c/a;

    for(int i=0; i<n; i++) {
        int tmp = (cal+d[i])/(cost+b);
        if(ans <= tmp) {
            ans = tmp;
            cost += b;
            cal += d[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
