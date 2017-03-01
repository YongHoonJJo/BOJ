#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int v, wSum;
char ck[100001];
struct Edge { int v, w; };
vector<Edge> g[100001];

void dfs(int s, int sum)
{
	int i, sz = g[s].size();
	ck[s] = 1;

	if(sum > wSum) {
		v = s;
		wSum = sum;
	}

	for(i=0; i<sz; i++) 
		if(!ck[g[s][i].v]) 
			dfs(g[s][i].v, sum+g[s][i].w);

}

int main()
{
	int i, a, b, w;
	scanf("%d", &v);

	while(v--) {
		scanf("%d", &a);

		while(1) {
			Edge e;

			scanf("%d", &b);
			if(b == -1) break;

			scanf("%d", &w);
			e.v = b; e.w = w;
			g[a].push_back(e);
		}
	}

	dfs(1, 0);
	memset(ck, 0, sizeof(ck));
	dfs(v, 0);
	printf("%d\n", wSum);

	return 0;
}


