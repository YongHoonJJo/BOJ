#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int g[101];
bool visited[101], finished[101];
vector<int> ans;

void dfs(int cur)
{
	visited[cur] = 1;

	int next = g[cur];
	if(!visited[next]) dfs(next);
	else {
		if(!finished[next]) {
			for(int j=next; !finished[j]; j=g[j]) {
				finished[j] = 1;
				ans.push_back(j);
			}
		}
	}
	finished[cur] = 1;
}

int main()
{
	int n, k;
	scanf("%d", &n);

	for(int i=1; i<=n; i++) {
		scanf("%d", &k);
		g[i] = k;
	}

	for(int i=1; i<=n; i++)
		if(!visited[i])
			dfs(i);
	
	int sz = ans.size();
	sort(ans.begin(), ans.end());
	printf("%d\n", sz);
	for(int i=0; i<sz; i++)
		printf("%d\n", ans[i]);

	return 0;
}
