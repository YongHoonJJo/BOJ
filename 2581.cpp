#include <stdio.h>
#define MAXN 10001
int prime[MAXN];

void setPrime()
{
	int i, j;
	for(i=2; i<MAXN; i++) prime[i]=1;
	for(i=2; i*i<MAXN; i++) {
		if(prime[i]) {
			for(j=i*i; j<MAXN; j+=i)
				prime[j] = 0;
		}
	}
}

int main()
{
	int i, n, m;
	int sum=0, Min=-1;
	scanf("%d%d", &m, &n);

	setPrime();	
	for(i=m; i<=n; i++) {
		if(prime[i]) {
			sum += i;
			if(Min == -1)
				Min = i;
		}
	}
	if(sum) printf("%d\n", sum);
	printf("%d\n", Min);

	return 0;
}
