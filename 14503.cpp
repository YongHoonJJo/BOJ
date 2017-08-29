#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct P { int r, c, d; };

int g[55][55];
int nextR[]={0, -1, 0, 1};
int nextC[]={-1, 0, 1, 0};
int backR[]={1, 0, -1, 0};
int backC[]={0, -1, 0, 1};

int main()
{
	int n, m;
	int r, c, d;
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &r, &c, &d);

	// 0 : 북쪽, 1 : 동쪽을, 
	// 2 : 남쪽을, 3 : 서쪽을 바라보고 있는 
	
	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++)
			scanf("%d", &g[i][j]);

	queue<P> q;
	q.push((P){r, c, d});		
	g[r][c] = 2;
	
	int ans = 1;
	while(!q.empty()) {
		int curR = q.front().r;
		int curC = q.front().c;
		int curD = q.front().d; q.pop();
	
		int nR = curR + nextR[curD];
		int nC = curC + nextC[curD];
		int nD = curD==0 ? 3 : curD-1;
		// 0>3, 3>2, 2>1, 1>0
		
		if(!g[nR][nC]) {
			q.push((P){nR, nC, nD});
			ans++;
			g[nR][nC] = 2;
		}
		else {
			int cnt=0;
			for(int i=0; i<4; i++)
				if(g[curR+nextR[i]][curC+nextC[i]])
					cnt++;
			if(cnt == 4) {
				int bR = curR+backR[curD];
				int bC = curC+backC[curD];
				if(g[bR][bC] != 1) 
					q.push((P){bR, bC, curD});
				else 
					break;
			}
			else {
				q.push((P){curR, curC, nD});	
			}
		}
	}
	printf("%d\n", ans);	
}
