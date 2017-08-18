#include <stdio.h>

int seg[1<<21];
int sIdx = (1<<21)/2;

void update(int i, int v)
{
	i += sIdx;
	seg[i] += v;

	while(i > 1) {
		i >>= 1;
		seg[i] = seg[i*2] + seg[i*2+1];
	}
}

int rank(int k, int nodeN, int nL, int nR)
{
	int mid = (nL + nR)/2;
	if(nL == nR) return nL;
	if(seg[nodeN*2] < k) return rank(k-seg[nodeN*2], nodeN*2+1, mid+1, nR);
	return rank(k, nodeN*2, nL, mid); 
}

int main()
{
	int n;
	scanf("%d", &n);

	while(n--) {
		int a, b, c;
		scanf("%d%d", &a, &b);
		if(a == 1) {
			int k = rank(b, 1, 0, sIdx-1);
			printf("%d\n", k);
			update(k, -1);
		}
		else {
			scanf("%d", &c);
			update(b, c); 
		}
	}
	return 0;
}
