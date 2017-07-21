#include <stdio.h>

char g[50][51], ck[50][50];
int row, col, ans;
int s[1000], top;
int q[10000], f, r;
int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};

int safe(int x, int y)
{
	return (0 <= x && x < col) && (0 <= y && y < row);
}

int main()
{
	int i, j, x, y, k;
	scanf("%d %d", &row, &col);

	for(i=0; i<row; i++)
		scanf("%s", g[i]);

	for(i=0; i<row; i++) {
		for(j=0; j<col; j++) {
			int cnt=0;
			if(g[i][j] == 'L') {
				for(k=0; k<4; k++) {
					x = j+dx[k];
					y = i+dy[k];
					if(!safe(x, y) || g[y][x] == 'W')
						cnt++;
				}
			}
			if(cnt >= 2 && !ck[i][j]) { 
				s[top++] = (i*100)+j;
				ck[i][j] = 1;
			}
		}
	}
	while(top) {

		for(i=0; i<row; i++)
			for(j=0; j<col; j++)
				ck[i][j] = 0;
		f = r = 0;

		q[r++] = s[--top]; 

		while(f != r) {
			int rr = r;

			while(f != rr) {
				y = q[f]/100;
				x = q[f++]%100;

				for(i=0; i<4; i++) {
					int xx, yy;
					yy = y+dy[i];
					xx = x+dx[i];
					if(safe(xx, yy) && g[yy][xx] == 'L' && !ck[yy][xx]) {
						ck[yy][xx] = ck[y][x]+1;
						q[r++] = (yy*100) + xx;
						if(ans < ck[yy][xx])
							ans = ck[yy][xx];
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
