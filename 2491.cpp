#include <stdio.h>

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, up=1, down=1, ans=1;
	int i, a[100001];
	scanf("%d", &n);

	for(i=0; i<n; i++)
		scanf("%d", a+i);

	for(i=1; i<n; i++) {
		if(a[i-1]<a[i]) {
			up++;
			down=1;
		}
		else if(a[i-1]==a[i]) {
			down++;
			up++;
		}
		else {
			up = 1;
			down++;
		}
		ans = Max(ans, up);
		ans = Max(ans, down);
	}
	printf("%d\n", ans);
	return 0;
}
