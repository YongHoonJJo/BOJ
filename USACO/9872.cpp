#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int ans=0;
    vector<string> v[1001];
    map<string, int> msi;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            char name[11];
            scanf("%s", name);
            v[i].push_back(name);
        }
        sort(v[i].begin(), v[i].end());
        string s;
        s = v[i][0]+' '+v[i][1]+' '+v[i][2];
        int tmp = ++msi[s];
        if(ans < tmp) ans = tmp;
    }
    printf("%d\n", ans);
    return 0;
}
