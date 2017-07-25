#include <stdio.h>

int main()
{
	int n, ans=0;
	int f, s, t;
	scanf("%d", &n);

	t = n;
	do {
		f = t/10;
		s = t%10;
		t = s*10 + (f+s)%10;
		ans++;
	} while(n != t);
	printf("%d\n", ans);
	return 0;
}
