#include <cstdio>
#include <map>
using namespace std;

int a[1001], b[1001];

map<int, int> mii;
long long int bCnt[600001];
int bIdx;


int main()
{
    int T, n, m;
    scanf("%d", &T);

    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", a+i);

    scanf("%d", &m);
    for(int i=0; i<m; i++)
        scanf("%d", b+i);

    for(int i=0; i<n; i++) {
        int sum=0;
        for(int j=i; j<n; j++) {
            sum += a[j];
            mii[sum]++;
        }
    }

    for(int i=0; i<m; i++) {
        int sum=0;
        for(int j=i; j<m; j++) {
            sum += b[j];
            bCnt[bIdx++] = sum;
        }
    }

    long long int ans=0LL;
    map<int, int>::iterator it;
    for(int i=0; i<bIdx; i++) {
        it = mii.lower_bound(T-bCnt[i]);
        if(it->first == T-bCnt[i])
            ans += it->second;
    }
    printf("%lld\n", ans); 
    return 0;
}
