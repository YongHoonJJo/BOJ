#include <stdio.h>
#include <queue>
using namespace std;

struct Point {
	int i, j;
};

int r, c, g[1001][1001];
int cnt, ans, di[]={1, 0, -1, 0}, dj[]={0, 1, 0, -1};
queue<Point> q;

int safe(int i, int j)
{
	return (0<= i && i < r) && (0<= j && j < c);
}

int main()
{
	int i, j, k;
	Point p;
	scanf("%d %d", &c, &r);

	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			scanf("%d", &g[i][j]);
			if(g[i][j] == 1) {
				cnt++;
				p.i = i;
				p.j = j;
				q.push(p);
			}
		}
	}

	while(!q.empty()) {
		i = q.front().i;
		j = q.front().j; q.pop();

		for(k=0; k<4; k++) {
			int nextI = i+di[k];
			int nextJ = j+dj[k];
			if(safe(nextI, nextJ) && !g[nextI][nextJ]) {
				g[nextI][nextJ] = g[i][j]+1;
				p.i = nextI;
				p.j = nextJ;
				q.push(p);
			}
		}
	}

	if(!cnt) ans = -1;
	else if(cnt != r*c) {
		for(i=0; i<r; i++) {
			for(j=0; j<c; j++) {
				if(!g[i][j]) {
					puts("-1");
					return 0;
				}
				if(ans < g[i][j])
					ans = g[i][j];
			}
		}
		ans--;
	}

	printf("%d\n", ans);
	return 0;
}


