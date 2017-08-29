#include <stdio.h>

int sIdx=1<<17;
int less[1<<18], more[1<<18];
int a[100001], Left[100001], Right[100001];

void update(int arr[], int i, int val)
{
	i += sIdx;
	arr[i] += val;

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
	int i, n;
	long long ans=0;
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
		// [0, i) 중 a[i]보다 큰 값의 개수 
		Right[i] = Sum(more, a[i]+1, n, 1, 0, sIdx-1);
		update(more, a[i], 1);
	}
	
	for(i=n-1; i>=0; i--) {
		// (i, n] 중 a[i]보다 작은 값의 개수
		Left[i] = Sum(less, 1, a[i]-1, 1, 0, sIdx-1);
		update(less, a[i], 1);
	}
	
	for(i=0; i<n; i++)
		ans += (1LL*Left[i]*Right[i]);
	printf("%lld\n", ans);
}
