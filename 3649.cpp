#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int x, n;
vector<int> lego;

void solve()
{
    for(int i=0; i<n-1; i++) {
        int cur = lego[i];
        if(binary_search(lego.begin()+i+1, lego.end(), x-cur)) {
            printf("yes %d %d\n", cur, x-cur);
            return ;
        }
    }
    puts("danger");
}

int main()
{
    while(scanf("%d", &x) == 1) {
        scanf("%d", &n);
        lego = vector<int>(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &lego[i]);
        }

        x *= 10000000;
        sort(lego.begin(), lego.end());
        solve();
    }
}

