#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n;
    scanf("%d", &n);

    while(n--) {
        int ans, diff;
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        int lbx, lby, rtx, rty;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        scanf("%d%d%d%d", &x3, &y3, &x4, &y4);

        ans = (x2-x1)*(y2-y1);

        rtx = min(x2, x4);
        rty = min(y2, y4);
        lbx = max(x1, x3);
        lby = max(y1, y3);
        
        diff = (rtx-lbx)*(rty-lby);

        printf("%d\n", ans-diff);
    }
    
    return 0;
}
