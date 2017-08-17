#include <stdio.h>

int main()
{
	int k, n, m, ans;
	scanf("%d%d%d", &k, &n, &m);

	ans = k*n - m;
	if(ans < 0) ans = 0;
	printf("%d\n", ans);

	return 0;
}
