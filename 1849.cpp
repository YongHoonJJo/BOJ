#include <stdio.h>

int seg[1<<18];
int sIdx = (1<<18)/2;
int ans[100001];

void update(int i, int val)
{
	i += sIdx;
	seg[i] = val;

	while(i > 1) {
		i /= 2;
		seg[i] = seg[i*2] + seg[i*2+1];
	}
}

int emptyCnt(int a, int node, int nodeL, int nodeR)
{
	int mid = (nodeL + nodeR) / 2;
	if(nodeL == nodeR) return nodeR;
	if(seg[node*2] < a) return emptyCnt(a-seg[node*2], node*2+1, mid+1, nodeR);
	return emptyCnt(a, node*2, nodeL, mid);
}

int main()
{
	int i, n, a, cnt;
	scanf("%d", &n);

	for(i=1; i<=n; i++)
		update(i, 1);
	
	for(i=1; i<=n; i++) {
		scanf("%d", &a);
		cnt = emptyCnt(a+1, 1, 0, sIdx-1); // i 앞의 빈칸의 수(i자리 포함)
		update(cnt, 0);
		ans[cnt] = i;
	}

	for(i=1; i<=n; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}
