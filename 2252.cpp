#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int ind[32001];
vector<int> v[32001];

int main()
{
	int i, n, m;
	scanf("%d %d", &n, &m);

	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		ind[b]++;
	}

	queue<int> q;
	for(i=1; i<=n; i++)
		if(!ind[i])
			q.push(i);

	while(!q.empty()) {
		int x = q.front(); q.pop();
		printf("%d ", x);

		for(i=0; i<v[x].size(); i++) {
			int y = v[x][i];
			ind[y]--;
			if(!ind[y])
				q.push(y);
		}
	}
	
}
