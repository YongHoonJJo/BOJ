#include <stdio.h>

long long arr[300000];
int sIdx=1;

void update(int i, int val)
{
	i += sIdx;
	arr[i] = val;

	while(i) {
		i >>= 1;
		arr[i] = arr[i*2]+arr[i*2+1];
	}
}

long long sum(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return arr[nodeNum];
	return sum(L, R, nodeNum*2, nodeL, mid)+sum(L, R, nodeNum*2+1, mid+1, nodeR);
}

int main()
{
	int i, n, q;
	int s, e;
	scanf("%d %d", &n, &q);

	while(sIdx < n)
		sIdx <<= 1;

	for(i=0; i<n; i++)
		scanf("%lld", &arr[sIdx+i]);

	s = sIdx>>1; e = sIdx;
	while(s) {
		for(i=s; i<e; i++)
			arr[i] = arr[i*2]+arr[i*2+1];
		e = s;
		s >>= 1;
	}

	while(q--) {
		int x, y, a, b, t;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if(x > y) { t=x; x=y; y=t; }
		printf("%lld\n", sum(x-1, y-1, 1, 0, sIdx-1));
		update(a-1, b);
	}

	return 0;
}
