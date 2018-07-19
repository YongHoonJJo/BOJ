#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct P { int r, c; };

int n;
int g[101][101];
int dr[]={1, 0, -1, 0};
int dc[]={0, 1, 0, -1};

bool safe(int r, int c)
{
    return (0 <= r && r < n) && (0 <= c && c < n);
}

bool canMove(int Min, int Max)
{
    bool visited[101][101]={0};

    queue<P> q;
    visited[0][0] = 1;
    q.push((P){0, 0});
    
    while(!q.empty()) {
        int curR = q.front().r;
        int curC = q.front().c; q.pop();

        for(int k=0; k<4; k++) {
            int nr = curR+dr[k];
            int nc = curC+dc[k];
            if(safe(nr, nc) && !visited[nr][nc] && Min <= g[nr][nc] && g[nr][nc] <= Max) {
                if(nr == n-1 && nc == n-1) {
                    return true;
                }
                q.push((P){nr, nc});
                visited[nr][nc] = 1;
            }
        }
    }
    return false;
}

bool isPossible(int mid)
{
    int Min = g[0][0];
    int Max = Min+mid;
    for(int i=0; i<=mid; i++) {
        if(Max > 200) {
            Min = Min - (Max-200);
            Max = 200;
        }
        if(canMove(Min, Max))
            return true;
        Max--; if(Max < g[0][0]) return false;
        Min--; if(Min < 0) return false;
    }
    return false;
}


int main()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &g[i][j]);

    int s = 0;
    int e = 200;

    while(s <= e) {
        int mid = (s+e)>>1;
        if(isPossible(mid)) e = mid-1;
        else s = mid+1;
    }
    printf("%d\n", e+1);
    return 0;
}

