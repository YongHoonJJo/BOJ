#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> P;

vector<P> v[10001];
bool visited[10001];
int ans, lastN;

void dfs(int cur, int cost)
{
	visited[cur] = 1;
	if(cost > ans) {
		ans = cost;
		lastN = cur;
	}

	for(int i=0; i<v[cur].size(); i++) {
		int next = v[cur][i].first;
		if(!visited[next])
			dfs(next, cost+v[cur][i].second);
	}
}

int main()
{
	int i, n;

	scanf("%d", &n);
	while(--n) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		v[a].push_back(P(b, w));
		v[b].push_back(P(a, w));
	}

	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	dfs(lastN, 0);
	printf("%d\n", ans);
}
