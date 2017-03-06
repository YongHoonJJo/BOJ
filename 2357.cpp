#include <stdio.h>

int segMax[300000], segMin[300000];
int sIdx=1;

int Min(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	int a, b, mid = (nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 0x7fffffff;
	if(L <= nodeL && nodeR <= R) return segMin[nodeNum];
	
	a = Min(L, R, nodeNum*2, nodeL, mid);
	b = Min(L, R, nodeNum*2+1, mid+1, nodeR);
	return a < b ? a : b;
}

int Max(int L, int R, int nodeNum, int nodeL, int nodeR)
{
	int a, b, mid = (nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return segMax[nodeNum];
	
	a = Max(L, R, nodeNum*2, nodeL, mid);
	b = Max(L, R, nodeNum*2+1, mid+1, nodeR);
	return a > b ? a : b;
}

int main()
{
	int i, n, k;
	int s, e;
	scanf("%d %d", &n, &k);

	while(sIdx < n)
		sIdx <<= 1;

	for(i=sIdx; i<sIdx+n; i++) {
		scanf("%d", &segMax[i]);
		segMin[i] = segMax[i];
	}

	s = sIdx>>1; e = sIdx;
	while(s) {
		for(i=s; i<e; i++) {
			segMax[i] = segMax[i*2]>segMax[i*2+1] ? segMax[i*2] : segMax[i*2+1];
			segMin[i] = segMin[i*2]<segMin[i*2+1] ? segMin[i*2] : segMin[i*2+1];
		}
		e = s;
		s >>= 1;
	}

	while(k--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n", Min(a-1, b-1, 1, 0, sIdx-1), Max(a-1, b-1, 1, 0, sIdx-1)); 
	}

	return 0;
}
