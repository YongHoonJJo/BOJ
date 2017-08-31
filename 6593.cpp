#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct P { int l, r, c; };

int L, R, C;

int safe(int l, int r, int c)
{
	return (0 <= l && l < L) && (0 <= r && r < R) && (0 <= c && c < C);
}

int main()
{
	while(1) {
		char g[31][31][31]={0};
		int visited[31][31][31]={0};
		int dL[] = {1, -1, 0, 0, 0, 0};
		int dR[] = {0, 0, 1, 0, -1, 0};
		int dC[] = {0, 0, 0, 1, 0, -1};

		scanf("%d%d%d", &L, &R, &C);
		if(!L) return 0;
		
		int EL, ER, EC;
		queue<P> q;
		for(int i=0; i<L; i++) {
			for(int j=0; j<R; j++) {
				for(int k=0; k<C; k++) {
					scanf(" %c", &g[i][j][k]);
					if(g[i][j][k] == 'S') {
						q.push((P){i, j, k});
						visited[i][j][k] = 1;
					}
					if(g[i][j][k] == 'E') {
						g[i][j][k] = '.';
						EL = i; ER = j; EC = k;
					}
				}
			}
		}
		
		while(!q.empty()) {
			int curL = q.front().l;
			int curR = q.front().r;
			int curC = q.front().c; q.pop();

			for(int k=0; k<6; k++) {
				int nextL = curL+dL[k];
				int nextR = curR+dR[k];
				int nextC = curC+dC[k];

				if(safe(nextL, nextR, nextC) && g[nextL][nextR][nextC]=='.' && !visited[nextL][nextR][nextC]) {
					visited[nextL][nextR][nextC] = visited[curL][curR][curC]+1;
					q.push((P){nextL, nextR, nextC});
				}
			}
		}

		int ans = visited[EL][ER][EC];
		if(!ans) puts("Trapped!");
		else printf("Escaped in %d minute(s).\n", ans-1);
	}
}
