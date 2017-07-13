#include <stdio.h>
#include <string.h>

int vip[41], d[41];

int go(int n)
{
	int ret;
	if(n == 0 || n == 1) return 1;
	if(d[n] != -1) return d[n];
	if(vip[n]) return d[n] = go(n-1);
	ret = go(n-1);
	if(!vip[n-1]) ret += go(n-2);
	return d[n] = ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	while(m--) {
		int k;
		scanf("%d", &k);
		vip[k] = 1;
	}

	memset(d, -1, sizeof(d));
	printf("%d\n", go(n));	

	return 0;
}
