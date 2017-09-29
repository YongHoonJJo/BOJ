#include <stdio.h>

int main()
{
	int i, sx, sy, n;
	double ans;
	scanf("%d%d%d", &sx, &sy, &n);
	ans = (1.0*sx/sy)*1000;

	for(i=0; i<n; i++) {
		int x, y;
		double tmp;
		scanf("%d%d", &x, &y);
		tmp = (1.0*x/y)*1000;
		if(ans > tmp) ans = tmp;
	}
	printf("%.2lf\n", ans);
	return 0;
}
