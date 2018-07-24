#include <cstdio>
#include <vector>
#include <queue>
using namespace std;



int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> g[20001];
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    q.push(1);

    vector<int> visited(n+1, 0);
    visited[1] = 1;

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(auto next : g[cur]) {
            if(!visited[next]) {
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }
    
    int num=0, Max=0, cnt=0;
    
    for(int i=1; i<=n; i++) {
        if(Max < visited[i]) {
            Max = visited[i];
            num = i;
            cnt = 1;
        }
        else if(Max == visited[i]) {
            cnt++;
        }
    }
    printf("%d %d %d\n", num, Max-1, cnt);
    return 0;
}

