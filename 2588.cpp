#include <stdio.h>

int main()
{
	int a, b, ans=0, fac=1;
	scanf("%d%d", &a, &b);

	while(b) {
		int tmp = a*(b%10);
		printf("%d\n", tmp);
		ans += (fac*tmp);
		b /= 10;
		fac *= 10;
	}
	printf("%d\n",ans);
	return 0;
}
