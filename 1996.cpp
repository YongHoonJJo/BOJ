#include <cstdio>
#include <queue>
using namespace std;

struct P { int r, c, cnt; };

int n;
int ans[1001][1001];
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool safe(int a, int b)
{
    return (0 <= a && a < n) && (0 <= b && b < n);
}

int main()
{
    scanf("%d", &n);
    
    queue<P> q;
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++) {
            char ch;
            scanf(" %c", &ch);
            if(ch != '.') {
                q.push((P){r, c, ch-'0'});
                ans[r][c] = -1000;
            }
       }
    }

    while(!q.empty()) {
        int curR = q.front().r;
        int curC = q.front().c;
        int cnt = q.front().cnt; q.pop();
        
        for(int k=0; k<8; k++) {
            int nr = curR + dr[k];
            int nc = curC + dc[k];
            if(safe(nr, nc)) 
                ans[nr][nc] += cnt;
        }
    }

    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++) {
            if(ans[r][c] < 0) printf("%c", '*');
            else if(ans[r][c] > 9) printf("%c", 'M');
            else printf("%d", ans[r][c]);
        }
        puts("");
    }

    
    return 0;
}
