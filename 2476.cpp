#include <stdio.h>

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, ans=0;
	scanf("%d", &n);

	while(n--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a == b) {
			if(b == c) ans = Max(ans, 10000+c*1000);
			else ans = Max(ans, 1000+b*100);
		}
		else {
			if(b == c) ans = Max(ans, 1000+c*100);
			else if(a == c) ans = Max(ans, 1000+c*100);
			else {
				int t = a > b ? (a > c ? a : c) : (b > c ? b : c);
				ans = Max(ans, t*100);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
