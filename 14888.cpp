#include <stdio.h>

int a[15], op[4];

int ansN = 1e9;
int ansX = -1e9;
int set[15];

void go(int n, int ps, int mi, int mu, int dv)
{
    if(n == 1) {
        int ans = a[1];
        for(int i=2; set[i]; i++) {
            if(set[i] == 1) ans += a[i];
            else if(set[i] == 2) ans -= a[i];
            else if(set[i] == 3) ans *= a[i];
            else {
                if(ans < 0) {
                    ans *= -1;
                    ans /= a[i];
                    ans *= -1;
                }
                else
                    ans /= a[i];
            }
        }
        if(ans > ansX) ansX = ans;
        if(ans < ansN) ansN = ans;
    }

    if(ps) { set[n]=1; go(n-1, ps-1, mi, mu, dv); }
    if(mi) { set[n]=2; go(n-1, ps, mi-1, mu, dv); }
    if(mu) { set[n]=3; go(n-1, ps, mi, mu-1, dv); }
    if(dv) { set[n]=4; go(n-1, ps, mi, mu, dv-1); }
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", a+i);

    for(int i=0; i<4; i++)
        scanf("%d", op+i);

    go(n, op[0], op[1], op[2], op[3]);
    printf("%d\n%d\n", ansX, ansN);
    return 0;
}
