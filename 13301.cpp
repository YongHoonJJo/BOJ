#include <stdio.h>

int main()
{
	int i, n;
	long long t[81]={0LL, 1LL, }, ans=0LL;
	scanf("%d", &n);

	for(i=2; i<=80; i++) 
		t[i] = t[i-1]+t[i-2];

	printf("%lld\n", (t[n]*2LL)+(t[n-1]+t[n])*2LL);	
	return 0;
}
