#include <stdio.h>

int main()
{
	int i, j, m, n;
	int sum=0, Min=-1;
	scanf("%d%d", &m, &n);

	for(i=1; i<=10000; i++) {
		int k = i*i;
		if(m <= k && k <= n) {
			if(Min == -1) Min = k;
			sum += k;
		}
	}
	if(Min != -1) printf("%d\n", sum);
	printf("%d\n", Min);
	return 0;
}
