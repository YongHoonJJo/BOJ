#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &a, &b, &m);

	vector<vector<int> > v(n+1);
	while(m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	queue<int> q;
	vector<int> visited(n+1, 0);	

	q.push(a);
	visited[a] = 1;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
	
		for(int i=0; i<v[cur].size(); i++) {
			int next = v[cur][i];
			if(!visited[next]) {
				q.push(next);
				visited[next] = visited[cur]+1;
			}
		}
	}
	printf("%d\n", visited[b]-1);
}
