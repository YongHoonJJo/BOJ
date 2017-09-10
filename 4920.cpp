#include <stdio.h>
#define MINF -100000000

int n, ans, tc;
int g[101][101];

int di[13][4]={
	{0, 0, 0, 0}, {0, 1, 2, 3},
	{0, 0, 1, 1},
	{0, 1, 2, 2}, {0, 1, 1, 1}, {0, 0, 0, 1}, {0, 0, 1, 2},
	{0, 1, -1, 0}, {0, 0, 1, 1},
	{0, 0, 0, -1}, {0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}
};

int dj[13][4]={
	{0, 1, 2, 3}, {0, 0, 0, 0},
	{0, 1, 0, 1},
	{0, 0, 0, -1}, {0, 0, 1, 2}, {0, 1, 2, 2}, {0, 1, 0, 0},
	{0, 0, 1, 1}, {0, 1, 1, 2},
	{0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}
};

int safe(int r, int c)
{
	return (0 <= r && r < n) && (0 <= c && c < n);
}

int main()
{
	while(1) {
		int i, j, y, x;	
		scanf("%d", &n);
		if(!n) break;

		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				scanf("%d", &g[i][j]);

		tc++; ans=MINF;
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				for(y=0; y<13; y++) {
					int tmp = 0;
					for(x=0; x<4; x++) {
						int nI = i+di[y][x];
						int nJ = j+dj[y][x];
						tmp += (safe(nI, nJ) ? g[nI][nJ] : MINF);
					}
					if(ans < tmp)
						ans = tmp;
				}
			}
		}
		printf("%d. %d\n", tc, ans);
	}
	return 0;
}
