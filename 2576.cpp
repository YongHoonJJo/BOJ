#include <stdio.h>

int main()
{
	int i, n, sum=0, Min=-1;

	for(i=0; i<7; i++) {
		scanf("%d", &n);
		if(n&1) {
			sum += n;
			if(Min == -1 || Min > n)
				Min = n;
		}	
	}
	if(Min != -1) printf("%d\n", sum);
	printf("%d\n", Min);

	return 0;
}
