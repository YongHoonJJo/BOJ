#include <stdio.h>
#include <queue>
using namespace std;

struct Point { int i, j; };

int r, c, g[102][102];
int di[]={1, 0, -1, 0}, dj[]={0, 1, 0, -1};
queue<Point> q;

int main()
{
	int i, j, k;
	Point p;

	scanf("%d %d", &r, &c);

	for(i=1; i<=r; i++)
		for(j=1; j<=c; j++)
			scanf("%1d", &g[i][j]);

	p.i = 1; p.j = 1;
	q.push(p);

	while(!q.empty()) {
		i = q.front().i;
		j = q.front().j; q.pop();

		for(k=0; k<4; k++) {
			int nextI = i+di[k];
			int nextJ = j+dj[k];

			if(g[nextI][nextJ] == 1) {
				p.i = nextI;
				p.j = nextJ;
				q.push(p);
				g[nextI][nextJ] = g[i][j]+1;
			}
		}
	}
	printf("%d\n", g[r][c]);
	return 0;
}


