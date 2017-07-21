#include <stdio.h>
#include <string.h>
#define INF	1000000000

char no[41];
long long d[41];

long long go(int n)
{
	long long ret=0LL;
	if(n <= 0) return 1;
	if(d[n]) return d[n];

	if(no[n]-'0' == 0) {
		if(1 <= no[n-1]-'0' && no[n-1]-'0' <= 3)
			return d[n] = go(n-2);
		else
			return INF;
	}

	if(1 <= no[n]-'0' && no[n]-'0' <= 4)
		if(1 <= no[n-1]-'0' && no[n-1]-'0' <= 3)
			ret += go(n-2);

	if(5 <= no[n]-'0' && no[n]-'0' <= 9)
		if(1 <= no[n-1]-'0' && no[n-1]-'0' <= 2)
			ret += go(n-2);
	ret += go(n-1);
	return d[n] = ret;
}

int main()
{
	int n;
	long long ans=0LL;
	scanf("%s", no);
	if(no[0] != '0') {
		n = strlen(no);
		ans = go(n-1);
		if(ans >= INF) ans = 0LL;
	}
	printf("%lld\n", ans);
	return 0;
}
