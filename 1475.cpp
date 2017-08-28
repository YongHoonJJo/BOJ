#include <stdio.h>

int check[10];

int main()
{
	int i, n, ans=0;
	scanf("%d", &n);

	while(n) {
		int k = n%10;
		n /= 10;
		if(k == 6 || k == 9) k = check[6]<check[9] ? 6 : 9;
		check[k]++;
	}

	for(i=0; i<10; i++)
		if(ans < check[i])
			ans = check[i];
	printf("%d\n", ans);
	return 0;
}
