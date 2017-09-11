#include <stdio.h>

char a[5000];

int main()
{
	int i, n, k, t, mod;	

	scanf("%d %d", &n, &k);

	t = k-1;
	mod = n;

	printf("<");
	while(n != 1) {
		int gap=k;
		a[t] = 1;
		printf("%d, ", t+1);
		while(gap--) {
			t++;
			t%=mod;
			if(a[t]) gap++;
		}
		n--;
	}

	for(i=0; i<mod; i++)
		if(!a[i])
			printf("%d>\n", i+1);

	return 0;
}


