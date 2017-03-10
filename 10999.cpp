#include <stdio.h>
#define MAX 1<<21

long long segT[MAX], lazy[MAX];
int sIdx=1;

void propagate(int node, int nodeL, int nodeR)
{
	if(lazy[node]) {
		if(node < sIdx) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		segT[node] += lazy[node] * (nodeR-nodeL+1);
		lazy[node] = 0;
	}
}

void add(int L, int R, int K, int node, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	propagate(node, nodeL, nodeR);

	if(R < nodeL || nodeR < L) return ;
	if(L <= nodeL && nodeR <= R) {
		lazy[node] += K;
		propagate(node, nodeL, nodeR);
		return ;
	}
	add(L, R, K, node*2, nodeL, mid);
	add(L, R, K, node*2+1, mid+1, nodeR);
	segT[node] = segT[node*2] + segT[node*2+1];
}

long long sum(int L, int R, int node, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	propagate(node, nodeL, nodeR);
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return segT[node];
	return sum(L, R, node*2, nodeL, mid)+sum(L, R, node*2+1, mid+1, nodeR);
}

int main()
{
	int i, n, m, k;
	int s, e, q;
	scanf("%d %d %d", &n, &m, &k);

	while(sIdx < n)
		sIdx <<= 1;

	for(i=0; i<n; i++)
		scanf("%lld", &segT[sIdx+i]);

	s = sIdx>>1; e = sIdx;
	while(s) {
		for(i=s; i<e; i++)
			segT[i] = segT[i*2]+segT[i*2+1];
		e = s;
		s >>= 1;
	}

	q = m+k;
	while(q--) {
		int a, b, c, d;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1) {
			scanf("%d", &d);
			add(b-1, c-1, d, 1, 0, sIdx-1);		
		}
		else {
			printf("%lld\n", sum(b-1, c-1, 1, 0, sIdx-1));
		}
	}
		

	return 0;
}
