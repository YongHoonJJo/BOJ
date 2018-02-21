#include <stdio.h>

int n, m;
int g[1001][1001];
int visited[1001];

void dfs(int s)
{
    int i;
    visited[s] = 1;

    for(i=1; i<=n; i++) {
        if(g[s][i] && !visited[i])
            dfs(i);
    }

}

int main()
{
    int i, ans=0;
    scanf("%d%d", &n, &m);

    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }

    for(i=1; i<=n; i++) {
        if(!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
