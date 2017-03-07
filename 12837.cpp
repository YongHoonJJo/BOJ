#include <stdio.h>

long long seg[3000000];
int sIdx=1;

void update(int i, int val)
{
	i += sIdx;
	seg[i] += val;

	while(i != 1) {
		i >>= 1;
		seg[i] = seg[i*2]+seg[i*2+1];
	}
}

long long sum(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return seg[nodeNum];
	return sum(L, R, nodeNum*2, nodeL, mid)+sum(L, R, nodeNum*2+1, mid+1, nodeR);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	while(sIdx < n)
		sIdx <<= 1;

	while(k--) {
		int q, a, b;
		scanf("%d %d %d", &q, &a, &b);
		if(q == 1) update(a-1, b);
		else printf("%lld\n", sum(a-1, b-1, 1, 0, sIdx-1));
	}

	return 0;
}
