#include <stdio.h>

int col, row, h, zero, ans;
int g[100][100][100];
int q[1000000], f, r;

int safe(int x, int y, int z)
{
	return (0 <= x && x < col) && (0 <= y && y < row) && (0 <= z && z < h);
}

int main()
{
	int i, j, k, rr, x, y, z;
	int dx[]={0, 0, 1, 0, -1, 0}, dy[]={0, 0, 0, 1, 0, -1}, dz[]={1, -1, 0, 0, 0, 0};
	scanf("%d %d %d", &col, &row, &h);

	for(i=0; i<h; i++) {
		for(j=0; j<row; j++) {
			for(k=0; k<col; k++) {
				scanf("%d", &g[i][j][k]);
				if(g[i][j][k] == 1) {
					q[r++] = (i*10000)+(j*100)+k;
				}
				else if(!g[i][j][k])
					zero++;
			}
		}
	}

	if(r != row*col*h) {
		while(f != r) {
			rr = r;
			ans++;

			while(f != rr) {
				z = q[f]/10000;
				y = (q[f]%10000)/100;
				x = q[f++]%100;

				for(i=0; i<6; i++) {
					int xx, yy, zz;
					xx = x+dx[i];
					yy = y+dy[i];
					zz = z+dz[i];

					if(safe(xx, yy, zz) && !g[zz][yy][xx]) {
						zero--;
						g[zz][yy][xx] = 1;
						q[r++] = (zz*10000)+(yy*100)+xx;
					}
				}
			}
		}
		if(zero)
			ans = -1;
		else 
			ans--;
	}
	printf("%d\n", ans);
	return 0;
}


