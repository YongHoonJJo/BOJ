#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m, s;
int g[1001][1001];
bool visited[1001];

void dfs(int s)
{
    visited[s] = 1;
    printf("%d ", s);

    for(int i=1; i<=n; i++) {
        if(g[s][i] && !visited[i])
            dfs(i);
    }
}

void bfs(int s)
{
    queue<int> q;

    q.push(s);
    visited[s] = 1;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        printf("%d ", cur);
        for(int i=1; i<=n; i++) {
            if(g[cur][i] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);

    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }

    dfs(s);
    puts("");
    
    memset(visited, 0, sizeof(visited));
    bfs(s);
}
