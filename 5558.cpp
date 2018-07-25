#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct P { int r, c; };

int h, w, n;
char g[1001][1001];
P check[10];

int dr[]={1, 0, -1, 0};
int dc[]={0, 1, 0, -1};

bool safe(int r, int c)
{
    return (0 <= r && r < h) && (0 <= c && c < w);
}

int bfs(int s, int t)
{
    int r = check[s].r;
    int c = check[s].c;

    int visited[1001][1001]={0};
    visited[r][c] = 1;

    queue<P> q;
    q.push((P){r, c});
    
    while(!q.empty()) {
        int curR = q.front().r;
        int curC = q.front().c; q.pop();
        
        for(int k=0; k<4; k++) {
            int nr = curR+dr[k];
            int nc = curC+dc[k];
            if(safe(nr, nc) && !visited[nr][nc] && g[nr][nc] != 'X') {
                if(g[nr][nc] == '0'+t) {
                    return visited[curR][curC];
                }
                q.push((P){nr, nc});
                visited[nr][nc] = visited[curR][curC] + 1;
            }
        }
    }
    return 0; 
}

int main()
{
    scanf("%d%d%d", &h, &w, &n);

    for(int r=0; r<h; r++) {
        scanf("%s", g[r]);
        for(int c=0; c<w; c++) {
            char ch = g[r][c];
            if(ch != '.' && ch != 'X') {
                if('1' <= ch && ch <= '0'+n) 
                    check[ch-'0'] = (P){r, c};
                else
                    check[0] = (P){r, c}; // 'S'
            }
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++) 
        ans += bfs(i-1, i);
    printf("%d\n", ans);
    return 0;
}

