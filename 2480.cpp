#include <stdio.h>

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int a, b, c;
	int ans=0;
	scanf("%d%d%d", &a, &b, &c);

	if(a == b && b == c)
		ans = 10000 + a*1000;
	else {
		if(a == b || b == c)
			ans = 1000 + b*100;
		else if(c == a)
			ans = 1000 + a*100;
		else {
			ans = Max(a, Max(b, c));
			ans = ans*100;
		}
	}
	printf("%d\n", ans);
	return 0;
}
