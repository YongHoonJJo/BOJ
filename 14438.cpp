#include <stdio.h>

int arr[1<<19];
int sIdx=1;

void update(int i, int v)
{
	i += sIdx;
	arr[i] = v;
	while(i != 1) {
		i >>= 1;
		arr[i] = arr[i*2]<arr[i*2+1]?arr[i*2]:arr[i*2+1];
	}
}

int getMin(int L, int R, int nodeN, int nodeL, int nodeR)
{
	int a, b, mid=(nodeL+nodeR)/2;
	if(nodeR < L || R < nodeL) return 0x7fffffff;
	if(L <= nodeL && nodeR <= R) return arr[nodeN];
	a = getMin(L, R, nodeN*2, nodeL, mid);
	b = getMin(L, R, nodeN*2+1, mid+1, nodeR);
	return a < b ? a : b;
}

int main()
{
	int i, n, m;
	int s, e;
	scanf("%d", &n);

	while(sIdx<n)
		sIdx <<= 1;

	for(i=0; i<n; i++)
		scanf("%d", &arr[sIdx+i]);

	s = sIdx>>1;
	e = sIdx;

	while(s) {
		for(i=s; i<e; i++) {
			arr[i] = arr[i*2]<arr[i*2+1] ? arr[i*2] : arr[i*2+1];
		}
		e = s;
		s >>= 1;
	}

	scanf("%d", &m);
	while(m--) {
		int q, a, b;
		scanf("%d%d%d", &q, &a, &b);
		if(q == 1) 
			update(a-1, b);
		else {
			if(a > b) { int t=a; a=b; b=t; }
			printf("%d\n", getMin(a-1, b-1, 1, 0, sIdx-1));
		}
	}

	return 0;
}
