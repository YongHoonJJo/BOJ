#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	(n%4 == 0) && (n%100!=0 || n%400==0) ? puts("1") : puts("0");
	return 0;
}
