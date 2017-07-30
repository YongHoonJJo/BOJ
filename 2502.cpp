#include <stdio.h>

int main()
{
	int d, k;
	int a, i;
	int f1[31]={0}, f2[31]={0};
	scanf("%d%d", &d, &k);

	f1[2]=0; f2[2]=1;
	f1[3]=1; f2[3]=1;

	for(i=4; i<31; i++) {
		f1[i] = f1[i-1]+f1[i-2];
		f2[i] = f2[i-1]+f2[i-2];
	}

	for(a=1; a<=k; a++) {
		if((k-f1[d]*a)%f2[d] == 0) {
			printf("%d\n%d\n", a, (k-f1[d]*a)/f2[d]);
			return 0;
		}
	}
	return 0;
}
