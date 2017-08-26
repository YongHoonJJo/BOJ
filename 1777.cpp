#include <stdio.h>

int a[100001], ans[100001];
int seg[1<<18];
int sIdx=1<<17;

void update(int i, int val)
{
	i += sIdx;
	seg[i] = val;
	while(i > 1) {
		i >>= 1;
		seg[i] = seg[i*2]+seg[i*2+1];
	}	
}

int Cnt(int k, int node, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	if(nodeL == nodeR) return nodeL;
	if(seg[node*2+1] >= k) return Cnt(k, node*2+1, mid+1, nodeR);
	return Cnt(k-seg[node*2+1], node*2, nodeL, mid);
}

int main()
{
	int i, n;
	scanf("%d", &n);

	for(i=1; i<=n; i++) {
		scanf("%d", a+i);
		update(i, 1);
	}

	// Cnt() : 뒤에서부터 빈칸(1) 수의 합이 a[i]+1개인 위치
	for(i=n; i>0; i--) {
		int idx = Cnt(a[i]+1, 1, 0, sIdx-1);
		update(idx, 0);
		ans[idx] = i;		
	}
	
	for(i=1; i<=n; i++)
		printf("%d ", ans[i]);

	return 0;
}
