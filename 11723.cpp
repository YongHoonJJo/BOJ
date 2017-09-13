#include <stdio.h>

int main()
{
	int m, s=0;
	scanf("%d", &m);

	while(m--) {
		char op[10];
		int x;
		scanf("%s", op);

		switch(op[1]) {
			case 'd': scanf("%d", &x); s |= (1<<x); break;
			case 'e': scanf("%d", &x); s &= ~(1<<x); break;
			case 'h': scanf("%d", &x); s & (1<<x) ? puts("1") : puts("0"); break;
			case 'o': scanf("%d", &x); s = s & (1<<x) ? s&(~(1<<x)) : s|(1<<x); break;
			case 'l': s = -1; break;
			case 'm': s = 0; break;
		}
	}
	return 0;
}
