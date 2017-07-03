#include <stdio.h>

int zn, on;
int d0[41], d1[41];

long long fibo0(int n)
{
	if(d0[n]) return d0[n];
	if(!n) return 1;
	if(n == 1) return 0;
	return d0[n] = fibo0(n-1)+fibo0(n-2);
}

long long fibo1(int n)
{
	if(d1[n]) return d1[n];
	if(!n) return 0;
	if(n == 1) return 1;
	return d1[n] = fibo1(n-1)+fibo1(n-2);
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int n;
		scanf("%d", &n);
		
		printf("%lld %lld\n", fibo0(n), fibo1(n));
	}

	return 0;
}
