#include <stdio.h>

int seg[1<<18], top[1<<18];
int sIdx = 1<<17;
int seen[100001];

void update(int arr[], int i, int val)
{
	i += sIdx;
	arr[i] = val;

	while(i > 1) {
		i >>= 1;
		arr[i] = arr[i*2]+arr[i*2+1];
	}
}

int Sum(int arr[], int L, int R, int node, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return arr[node];
	return Sum(arr, L, R, node*2, nodeL, mid)+Sum(arr, L, R, node*2+1, mid+1, nodeR);
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int i, n, m;
		scanf("%d%d", &n, &m);
		
		for(i=1; i<=m; i++) {
			int k, ans;
			scanf("%d", &k);
		
			if(seen[k]) {
				update(top, seen[k], 0);
				update(top, i, 1);
				ans = Sum(top, seen[k], i-1, 1, 0, sIdx-1);
			}
			else {
				ans = k-1+Sum(seg, k+1, n, 1, 0, sIdx-1);
				update(seg, k, 1);
				update(top, i, 1);
			}
			printf("%d ", ans);
			seen[k] = i;	
		}

		for(i=1; i<=n; i++) {
			seen[i] = 0;
			update(seg, i, 0);
			update(top, i, 0);
		}
		puts("");
	}

	return 0;
}
