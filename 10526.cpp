#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;

lli L;
lli g[20][20];
int N, half, K;

map<int, vector<lli> > miv;

void twp(int cur, int status, lli dist, int cnt)
{
    if(cnt == half) {
        auto &p = miv[status];
        p.push_back(dist); 
        return ;
    }

    for(int i=1; i<N; i++) {
        if(!(status & 1<<i)) {
           twp(i, status|(1<<i), dist+g[cur][i], cnt+1); 
        }
    }
}

void twp2(int cur, int status, lli dist, int cnt)
{
    if(cnt == N-half) {
        int tmp = 0;
        for(int i=0; i<N; i++) 
            if(!(status & (1<<i))) 
                tmp |= (1<<i);
        tmp |= (1<<cur);
        auto &p = miv[tmp];
        vector<lli>::iterator it = lower_bound(p.begin(), p.end(), L-dist);
        if(it != p.end() && *it == L-dist) {
            puts("possible");
            exit(0);
        }
        return ;
    }
    
    for(int i=1; i<N; i++) {
        if(!(status & 1<<i)) {
           twp2(i, status|(1<<i), dist+g[cur][i], cnt+1); 
        }
    }
}

int main()
{
    scanf("%d%lld", &N, &L);

    for(int i=0; i<N; i++) {
        K |= (1<<i);
        for(int j=0; j<N; j++) {
            scanf("%lld", &g[i][j]);
        }
    }
    
    
    half = N>>1;
    twp(0, 1, 0LL, 0);

    for(auto it = miv.begin(); it!= miv.end(); it++)
        sort((it->second).begin(), (it->second).end());

    twp2(0, 0, 0LL, 0);

    puts("impossible");
    return 0;
}

