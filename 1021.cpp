#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> v;
    for(int i=1; i<=n; i++)
        v.push_back(i);

    int cur=0, ans=0;
    for(int i=0; i<m; i++) {
        int target, tmp = 0;
        int size = v.size();
        scanf("%d", &target);

        for(int j=0; j<size; j++) {
            if(v[cur] == target) {
                v.erase(v.begin()+cur);
                if(cur == size-1) cur = 0;
                break;
            }
            cur = (cur+1)%size;
            tmp++;
        }
        ans += min(tmp, size-tmp);
    }
    printf("%d\n", ans); 
}

