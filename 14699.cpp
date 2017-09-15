#include <cstdio>
#include <vector>
using namespace std;

int h[5001], d[5001];
vector<int> g[5001];

int go(int cur)
{
	int &ret = d[cur];
	if(ret != -1) return ret;

	ret = 1;
	for(int i=0; i<g[cur].size(); i++) {
		int next = g[cur][i];
		int tmp = go(next)+1;
		if(ret < tmp) ret = tmp;
	}
	return ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	for(int i=1; i<=n; i++) {
		scanf("%d", h+i);
		d[i] = -1;
	}

	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(h[a] > h[b]) { int t=a; a=b; b=t; }
		g[a].push_back(b);
	}

	for(int i=1; i<=n; i++)
		printf("%d\n", go(i));

	return 0;
}
