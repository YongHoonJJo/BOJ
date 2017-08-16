#include <stdio.h>

int main()
{
	int i, n, med[101];	
	scanf("%d", &n);

	for(i=0; i<101; i++)
		med[i] = -1;

	while(n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		med[a] = b;
	}

	scanf("%d", &n);
	while(n--) {
		int k, m, ok=1;
		int ans[101];
		scanf("%d", &k);
		for(i=0; i<k; i++) {
			scanf("%d", &m);
			if(med[m] != -1) ans[i] = med[m];
			else ok = 0; 
		}
		if(ok == 0) puts("YOU DIED");
		else {
			for(i=0; i<k; i++)
				printf("%d ", ans[i]);
			puts("");
		}
	}

	return 0;
}
