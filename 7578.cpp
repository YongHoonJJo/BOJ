#include <stdio.h>

int id[1000001];
int arr[1<<20];
int sIdx = 1<<19;

void update(int i, int val)
{
	i += sIdx;
	arr[i] = val;
	while(i > 1) {
		i >>= 1;
		arr[i] = arr[i*2]+arr[i*2+1];
	}
}

int Sum(int L, int R, int node, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return arr[node];
	return Sum(L, R, node*2, nodeL, mid)+Sum(L, R, node*2+1, mid+1, nodeR);
}

int main()
{
	int i, n, k;
	long long ans=0;
	scanf("%d", &n);

	for(i=1; i<=n; i++) {
		scanf("%d", &k);
		id[k] = i;
	}

	// 2 4 1 3 5 : ans = 3
	// 2 5 1 3 4 : ans = 4
	// 이전에 나왔던 값들 중, 현재 나온값보다 큰 값들의 갯수
	for(i=1; i<=n; i++) {
		scanf("%d", &k);
		update(id[k], 1);
		ans += (i-Sum(0, id[k], 1, 0, sIdx-1));	
	}
	printf("%lld\n", ans);
	return 0;
}
