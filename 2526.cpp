#include <stdio.h>

int main()
{
	int i, n, p, m, ans=0;
	int check[1001]={0};
	scanf("%d%d", &n, &p);

	m = n;
	while(!check[n]) {
		check[n] = 1;
		n *= m;
		n %= p;
	}

	while(check[n] != 2) {
		check[n] = 2;
		n *= m;
		n %= p;
	}

	for(i=0; i<1001; i++) 
		if(check[i] == 2)
			ans++;

	printf("%d\n", ans);
	return 0;
}
