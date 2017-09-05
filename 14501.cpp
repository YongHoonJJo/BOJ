#include <stdio.h>

int n;
int T[20], P[20];
int ans;

void dfs(int day, int sum)
{
	int i;
	if(day > n) return ;
	if(day < n) {
		dfs(day+T[day], sum+P[day]);
		dfs(day+1, sum);
	}
	if(ans < sum) ans = sum;
}

int main()
{
	int i;
	scanf("%d", &n);

	for(i=0; i<n; i++)
		scanf("%d%d", T+i, P+i);

	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}
