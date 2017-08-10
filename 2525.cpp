#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	while(c--) {
		b++;
		if(b == 60) {
			b = 0; a++;
			if(a == 24) a = 0;
		}
	}
	printf("%d %d\n", a, b);
	return 0;
}
