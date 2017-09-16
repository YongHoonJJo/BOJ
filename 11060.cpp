#include <cstdio>
#define INF	0x3f3f3f3f

int n;
int a[1001], d[1001];

int jump(int idx)
{
	int &ret = d[idx];
	if(idx >= n-1) return 0;
	if(ret != -1) return ret;

	ret = INF;
	for(int i=1; i<=a[idx]; i++) {
		int tmp = jump(idx+i)+1;
		if(ret > tmp) ret = tmp;	
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		scanf("%d", a+i);
		d[i] = -1;
	}

	int ans = jump(0);
	if(ans == INF) ans = -1;
	printf("%d\n", ans);
}
