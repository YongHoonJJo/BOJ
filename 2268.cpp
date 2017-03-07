#include <stdio.h>

long long arr[3000000];
int sIdx=1;

void modify(int i, int val)
{
	i += sIdx;
	arr[i] = val;

	while(i!=1) {
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
	int n, m;
	scanf("%d %d", &n, &m);

	while(sIdx < n)
		sIdx <<= 1;

	while(m--) {
		int q, a, b;
		scanf("%d %d %d", &q, &a, &b);
		if(q) modify(a-1, b);
		else {
			if(a > b) { int t=a; a=b; b=t; }	
			printf("%lld\n", sum(a-1, b-1, 1, 0, sIdx-1));
		}
	}

	return 0;
}
