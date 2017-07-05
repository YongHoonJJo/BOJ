#include <stdio.h>

int jd[1001];
int d[1001][31][3];

int max(int a, int b)
{
	return a > b ? a : b;
}

int go(int t, int w, int loc)
{
	int ans = 0;
	int a, b;

	if(t <= 0) return 0;
	if(d[t][w][loc]) return d[t][w][loc];

	if(jd[t] == loc+1)
		ans = 1;
	
	a = go(t-1, w, loc) + ans;
	if(w-1>=0) {
		b = go(t-1, w-1, (loc+1)%2) + ans;
		a = max(a, b);
	}
	return  d[t][w][loc] = a;
}

int main()
{
	int i, t, w;
	int ans=0;
	scanf("%d%d", &t, &w);
	
	for(i=1; i<=t; i++)
		scanf("%d", jd+i);
	
	ans = go(t, w, 0);
	ans = max(ans, go(t, w, 1));	
	printf("%d\n", ans);
	return 0;
}
