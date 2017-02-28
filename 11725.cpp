#include <cstdio>
#include <vector>
using namespace std;

#define MAX	100001

vector<int> g[MAX];
bool visited[MAX];
int parent[MAX];

void dfs(int cur)
{
	visited[cur] = true;
	
	for(int i=0; i<g[cur].size(); i++) {
		int next = g[cur][i];
		if(!visited[next]) {
			parent[next] = cur;
			dfs(next);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i=1; i<n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);	
	
	for(int i=2; i<=n; i++)
		printf("%d\n", parent[i]);

	return 0;
}
