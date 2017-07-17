#include <stdio.h>

int main()
{
	int a[9], ans[101]={0};		
	int i, j, sum=0;

	for(i=0; i<9; i++) {
		scanf("%d", a+i);
		sum += a[i];
	}

	for(i=0; i<8; i++) {
		for(j=i+1; j<9; j++) {
			if(sum-100 == a[i]+a[j]) {
				a[i] = a[j] = 0;
			}
		}
	}

	for(i=0; i<9; i++)
		if(a[i])
			ans[a[i]]++;
	for(i=1; i<101; i++)
		if(ans[i])
			printf("%d\n", i);

	return 0;
}
