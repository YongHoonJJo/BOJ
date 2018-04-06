#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct P { int r, c; };

int n;
int g[101][101];
int checked[101][101];

int dr[]={1, 0, -1, 0};
int dc[]={0, 1, 0, -1};

int min(int a, int b)
{
    return a < b ? a : b;
}

bool safe(int r, int c)
{
    return (0 <= r && r < n) && (0 <= c && c < n);
}

void dfs(queue<P> &q, int r, int c, int cnt)
{
    g[r][c] = cnt;

    for(int k=0; k<4; k++) {
        int nr = r+dr[k];
        int nc = c+dc[k];
        if(safe(nr, nc)) {
            if(g[nr][nc] == 1) { 
                dfs(q, nr, nc, cnt);
            }
            else {// g[nr][nc] == 0
                if(!checked[nr][nc]) {   
                    q.push((P){nr, nc});
                    checked[nr][nc] = 1;
                }
            }
        }
    }
}

int bfs(queue<P> &q, int cnt)
{
    while(!q.empty()) {
        int curR = q.front().r;
        int curC = q.front().c; q.pop();

        for(int k=0; k<4; k++) {
            int nr = curR + dr[k];
            int nc = curC + dc[k];
            if(safe(nr, nc) && g[nr][nc] != cnt && !checked[nr][nc]) {
                checked[nr][nc] = checked[curR][curC]+1;
                q.push((P){nr, nc});
                if(g[nr][nc] != 0) {
                    return checked[curR][curC];
                }
            }
        }
    }
    return 1e9;
}

int main()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &g[i][j]);

    int cnt = 1;
    int ans = 1e9;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(g[i][j] == 1) {
                cnt++;

                queue<P> q;
                dfs(q, i, j, cnt); 

                int tmp = bfs(q, cnt);
                ans = min(ans, tmp);

                memset(checked, 0, sizeof(checked));                
            }                
        }
    }
    printf("%d\n", ans);
}
