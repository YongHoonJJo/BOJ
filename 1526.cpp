#include <stdio.h>

int kms[1<<21];

int main()
{
	int n, idx=1;

	scanf("%d", &n);
	
	while(kms[idx] <= n) {
		kms[idx*2] = kms[idx]*10+4;
		kms[idx*2+1] = kms[idx]*10+7;
		idx++;
	}
	printf("%d\n", kms[idx-1]);
	return 0;
}
