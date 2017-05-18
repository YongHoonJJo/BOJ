#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define INF	1000000000

typedef pair<int, int> P;

int g[100][100];
int dist[100][100];
bool visited[100][100];

int r, c;
int di[]={1, 0, -1, 0}, dj[]={0, 1, 0, -1};

bool safe(int i, int j)
{
	return (0 <= i && i < r) && (0 <= j && j < c);
}

int main()
{
	int i, j;
	scanf("%d%d", &c, &r);

	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			scanf("%1d", &g[i][j]);
			dist[i][j] = INF;
		}
	}

	priority_queue<P, vector<P>, greater<P> > pq;
	pq.push(P(0, 0));
	dist[0][0] = 0;

	while(!pq.empty()) {
		int curI, curJ;
		do {
			curI = pq.top().second/100;
			curJ = pq.top().second%100;
			pq.pop();
		} while(!pq.empty() && visited[curI][curJ]);

		if(visited[curI][curJ]) break;

		visited[curI][curJ] = 1;

		for(int k=0; k<4; k++) {
			int nextI = curI+di[k];
			int nextJ = curJ+dj[k];
			if(safe(nextI, nextJ) && !visited[nextI][nextJ]) {
				if(dist[nextI][nextJ] > dist[curI][curJ] + g[nextI][nextJ]) {
					dist[nextI][nextJ] = dist[curI][curJ]+g[nextI][nextJ];
					pq.push(P(dist[nextI][nextJ], nextI*100+nextJ)); 
				}
			}
		}
	}
	printf("%d\n", dist[r-1][c-1]);
}
