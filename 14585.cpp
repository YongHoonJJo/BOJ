#include <stdio.h>

int d[302][302];
int ans;

int main()
{
	int i, j, n, m;	
	scanf("%d%d", &n, &m);

	while(n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		d[x+1][y+1] = m-y-x;	
	}

	for(i=1; i<=301; i++) {
		for(j=1; j<=301; j++) {
			d[i][j] += d[i-1][j] > d[i][j-1] ? d[i-1][j] : d[i][j-1];
			ans = ans > d[i][j] ? ans : d[i][j];
		}
	}

	printf("%d\n", ans);
	return 0;
}
