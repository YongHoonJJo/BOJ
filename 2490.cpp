#include <stdio.h>

int main()
{
	int tc=3;
	while(tc--) {
		int n=4, k, ans=0;
		while(n--) {
			scanf("%d", &k);
			ans += k;
		}
		switch(ans) {
			case 0: puts("D"); break;
			case 1: puts("C"); break;
			case 2: puts("B"); break;
			case 3: puts("A"); break;
			case 4: puts("E"); break;
		}
	}

	return 0;
}
