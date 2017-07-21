#include <stdio.h>

int main()
{
	int i, sum=0, max=0, ans=0;
	int n[10], check[101]={0};

	for(i=0; i<10; i++) {
		scanf("%d", n+i);
		sum += n[i];
		check[n[i]/10]++;
	}

	for(i=1; i<=100; i++) {
		if(max < check[i]) {
			max = check[i];
			ans = i;
		}
	}
	printf("%d\n", sum/10);
	printf("%d\n", ans*10);
	return 0;
}
