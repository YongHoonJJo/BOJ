#include <stdio.h>

int x, y, x2, y2;
char a[10], b[10];

int main()
{
	int i;
	scanf("%s%s", a, b);

	for(i=0; a[i]; i++) {
		int t = a[i]-'0';
		x *= 10; x2 *= 10;
		x += (t == 5 || t == 6) ? t = 6 : t;
		x2 += (t == 5 || t == 6) ? t = 5 : t;
	}
	for(i=0; b[i]; i++) {
		int t = b[i]-'0';
		y *= 10; y2 *= 10;
		y += (t == 5 || t == 6) ? t = 6 : t;
		y2 += (t == 5 || t == 6) ? t = 5 : t;
	}
	printf("%d %d\n", x2+y2, x+y);
	return 0;
}
