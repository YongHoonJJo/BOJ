#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<long long> v;
    map<long long, int> cnt;
    
    for(int i=0; i<n; i++) {
        long long k;
        scanf("%lld", &k);
        if(!cnt[k]) {
            v.push_back(k);        
            cnt[k] = 1;
        }
        else
            cnt[k]++;
    }

    sort(v.begin(), v.end());

    long long ans = v[0];
    for(int i=0; i<v.size(); i++) 
        if(cnt[ans] < cnt[v[i]]) 
            ans = v[i];

    printf("%lld\n", ans);
}

