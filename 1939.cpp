#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct P { int to, w; };

int n, m;
int x, y;
vector<vector<P> > v;

bool isPossible(int mid)
{
	queue<int> q;
	vector<bool> visited(v.size());
	q.push(x);
	visited[x] = 1;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for(int i=0; i<v[cur].size(); i++) {
			int next = v[cur][i].to;
			int w = v[cur][i].w;
			if(!visited[next] && mid <= w) {
				if(next == y) return 1;
				q.push(next);
				visited[next] = 1;
			}
		}
	}
	return 0;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	v = vector<vector<P> >(n+1);	
	while(m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back((P){b, c});
		v[b].push_back((P){a, c});
	}
	scanf("%d%d", &x, &y);

	int s = 1;
	int e = 1000000000;
	while(s <= e) {
		int mid = (s + e)/2;
		if(isPossible(mid)) s = mid+1;
		else e = mid-1;
	}
	printf("%d\n", e);
	return 0;
}
