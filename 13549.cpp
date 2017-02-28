#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX	100001
typedef pair<int, int> P;

int main()
{
	int n, k, ans=MAX;
	int visited[MAX];
	scanf("%d %d", &n, &k);

	queue<P> q;
	q.push(P(n, 0));
	fill(visited, visited+MAX, MAX);

	while(!q.empty()) {
		int sz=q.size();
		for(int i=0; i<sz; i++) {
			int x = q.front().first; 
			int t = q.front().second; q.pop();
			visited[x] = t;

			if(t < ans) { 
				if(x == k) {
					if(ans > t) ans = t;
				}
				else {
					if(x+1<MAX && visited[x+1]>t+1) q.push(P(x+1, t+1));
					if(x-1>=0 && visited[x-1]>t+1) q.push(P(x-1, t+1));
					if(x*2<MAX && visited[x*2]>t) q.push(P(x*2, t));
				}
			}
		}
	}
	printf("%d\n", ans);
}
