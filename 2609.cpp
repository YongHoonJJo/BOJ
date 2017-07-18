#include <stdio.h>

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a%b);	
}

int main()
{
	int a, b, g, l;
	scanf("%d%d", &a, &b);

	g = gcd(a, b);
	l = a * b / g;
	printf("%d\n%d\n", g, l);
	return 0;
}
