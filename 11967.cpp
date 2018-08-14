#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> v[10000];
bool check[100][100];
int visited[100][100];

int dr[]={1, 0, -1, 0};
int dc[]={0, 1, 0, -1};

bool safe(int r, int c)
{
    return (0 <= r && r < n) && (0 <= c && c < n);
}

bool bfs(int cnt)
{
    int re=0;
    
    queue<int> q;
    q.push(0);

    check[0][0] = 1;
    visited[0][0] = cnt;    

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i=0; i<v[cur].size(); i++) {
            int nR = v[cur][i]/100;
            int nC = v[cur][i]%100;
            if(!check[nR][nC]) {
                check[nR][nC] = 1;
                re = 1;
            }
        }

        for(int k=0; k<4; k++) {
            int nR = cur/100 + dr[k];
            int nC = cur%100 + dc[k];
            if(safe(nR, nC) && check[nR][nC] && visited[nR][nC] != cnt) {
                q.push(nR*100+nC);
                visited[nR][nC] = cnt;
            }
        }
    }

    return re;
}

int main()
{
    scanf("%d%d", &n, &m);

    while(m--) {
        int x, y, a, b;
        scanf("%d%d%d%d", &x, &y, &a, &b);
        x--; y--; a--; b--;
        v[x*100+y].push_back(a*100+b);
    }
    
    int cnt=1;
    while(bfs(cnt)) cnt++;

    int ans=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(check[i][j])
                ans++;
    printf("%d\n", ans);
    return 0;
}

