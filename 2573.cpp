#include <cstdio>
#include <queue>
using namespace std;

struct P { int r, c; };
struct M { int r, c, cnt; };

int r, c;
int g[301][301];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int visited[301][301];

queue<P> q;

void dfs(int i, int j, int &ans)
{
    visited[i][j] = ans;
    
    for(int k=0; k<4; k++) {
        int ni = i+dr[k];
        int nj = j+dc[k];
        if(g[ni][nj] && visited[ni][nj]!=ans)
            dfs(ni, nj, ans);
    }
}

int solve(int sum)
{
    int ans=0;
    while(sum) {
        ans++;
        queue<M> mq;
        while(!q.empty()) {
            int curR = q.front().r;
            int curC = q.front().c; q.pop();

            int cnt = 0;
            for(int k=0; k<4; k++) {
                int nr = curR + dr[k];
                int nc = curC + dc[k];
                if(!g[nr][nc]) cnt++;
            }
            mq.push((M){curR, curC, cnt});    
        }

        while(!mq.empty()) {
            int curR = mq.front().r;
            int curC = mq.front().c;
            int cnt = mq.front().cnt; mq.pop();

            if(g[curR][curC] > cnt) {
                q.push((P){curR, curC});
                g[curR][curC] -= cnt;
                sum -= cnt;
            }
            else {
                sum -= g[curR][curC];
                g[curR][curC] = 0;
            }
        }

        int cnt=0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(g[i][j] && visited[i][j]!=ans) {
                    cnt++;
                    dfs(i, j, ans);
                    if(cnt == 2) return ans;
                }
            }
        }
    } 
    return 0;
}

int main()
{
    scanf("%d%d", &r, &c);

    int sum = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%d", &g[i][j]);
            if(g[i][j]) q.push((P){i, j});
            sum += g[i][j];
        }
    }

    printf("%d\n", solve(sum));
    return 0;
}
