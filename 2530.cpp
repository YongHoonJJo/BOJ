#include <stdio.h>

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);

	while(d--) {
		c++;
		if(c == 60) {
			c = 0; b++;
			if(b == 60) {
				b = 0; a++;
				if(a == 24) a = 0;
			}
		}
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
}
