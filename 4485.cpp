#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define INF	1000000000
typedef pair<int, int> P;

int g[125][125], dist[125][125];
bool visited[125][125];
int di[]={1, 0, -1, 0}, dj[]={0, 1, 0, -1};

bool safe(int n, int i, int j)
{
	return (0 <= i && i < n) && (0 <= j && j < n);
}

int main()
{
	int tc=0;
	while(1) {
		int i, j, n;
		scanf("%d", &n);
		
		if(!n) return 0;

		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				scanf("%d", &g[i][j]);
				visited[i][j] = 0;
				dist[i][j] = INF;
			}
		}
		
		priority_queue<P, vector<P>, greater<P> > pq;
		dist[0][0] = 0;
		pq.push(P(0, 0));

		while(!pq.empty()) {
			int curI, curJ;
			do {
				curI = pq.top().second/1000;
				curJ = pq.top().second%1000;
				pq.pop();
			} while(!pq.empty() && visited[curI][curJ]);

			if(visited[curI][curJ]) break;
			
			visited[curI][curJ] = 1;

			for(int k=0; k<4; k++) {
				int nextI = curI+di[k];
				int nextJ = curJ+dj[k];
				if(safe(n, nextI, nextJ) && !visited[nextI][nextJ]) {
					if(dist[nextI][nextJ] > dist[curI][curJ]+g[nextI][nextJ]) {
						dist[nextI][nextJ] = dist[curI][curJ]+g[nextI][nextJ];
						pq.push(P(dist[nextI][nextJ], nextI*1000+nextJ));
					}
				}
			}
		}
		printf("Problem %d: %d\n", ++tc, dist[n-1][n-1]+g[0][0]);
	}
}
