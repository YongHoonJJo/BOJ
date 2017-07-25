#include <stdio.h>

int abs(int x)
{
	return x > 0 ? x : -x;
}

int Min(int a, int b)
{
	return a < b ? a : b; 
}

int main()
{
	int row, col, n, ans=0;
	int i, r[101], c[101];
	scanf("%d%d%d", &col, &row, &n);

	// dir == 1:north, 2:south, 3:west, 4:east
	for(i=0; i<=n; i++) {
		int dir, dist;
		scanf("%d%d", &dir, &dist);
		switch(dir) {
			case 1: r[i]=0; c[i]=dist; break;
			case 2: r[i]=row; c[i]=dist; break;
			case 3: r[i]=dist; c[i]=0; break;
			case 4: r[i]=dist; c[i]=col; break;
		}
	}

	for(i=0; i<n; i++) {
		ans += (abs(r[n]-r[i])+abs(c[n]-c[i]));
		if(abs(r[n]-r[i]) == row)
			ans += (Min(Min(abs(col-c[n]), c[n]), Min(abs(col-c[i]),c[i]))*2);
		if(abs(c[n]-c[i]) == col) {
			ans += (Min(Min(abs(row-r[n]), r[n]), Min(abs(row-r[i]),r[i]))*2);
		}
	}
	printf("%d\n", ans);
	return 0;
}
