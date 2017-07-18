#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	vector<vector<int> > v(n+1);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<bool> visited(n+1, 0);
	queue<int> q;

	int ans = 0;
	q.push(1);
	visited[1] = 1;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for(int i=0; i<v[cur].size(); i++) {
			int next = v[cur][i];
			if(!visited[next]) {
				q.push(next);
				visited[next] = 1;
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}
