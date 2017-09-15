#include <cstdio>
#include <cstring>

int n, m;
int d[301][21];
int benefit[301][21];
int result[301][21];

int invest(int rest, int num)
{
	if(rest == 0 || num == m) return 0;

	int &ret = d[rest][num];
	if(ret != -1) return ret;

	ret = invest(rest, num+1);
	for(int i=1; i<=rest; i++) {
		int tmp = invest(rest-i, num+1)+benefit[i][num];
		if(ret < tmp) {
			ret = tmp;
			result[rest][num] = i;
		}
	}
	return ret;	
}

void trace(int rest, int num)
{
	if(num == m) return ;
	int ret = result[rest][num];
	printf("%d ", ret);
	trace(rest-ret, num+1);
}

int main()
{
	scanf("%d%d", &n, &m);

	for(int i=0; i<n; i++) {
		int cost;
		scanf("%d", &cost);
		for(int j=0; j<m; j++)
			scanf("%d", &benefit[cost][j]);
	}

	memset(d, -1, sizeof(d));
	printf("%d\n", invest(n, 0));
	trace(n, 0);
	return 0;
}
