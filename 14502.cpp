#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct P { int i, j; };

int n, m;
int di[]={1, 0, -1, 0};
int dj[]={0, 1, 0, -1};
int g[10][10], cp[10][10];
vector<P> zero, virus;

bool safe(int i, int j)
{
	return (0 <= i && i < n) && (0 <= j && j < m);
}

int go()
{
	int i, j, k;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			cp[i][j] = g[i][j];
	
	queue<P> q;
	for(i=0; i<virus.size(); i++)
		q.push(virus[i]);
	
	while(!q.empty()) {
		int curI = q.front().i;
		int curJ = q.front().j;
		q.pop();

		for(k=0; k<4; k++) {
			int nextI = curI+di[k];
			int nextJ = curJ+dj[k];
			if(safe(nextI, nextJ) && !cp[nextI][nextJ]) {
				cp[nextI][nextJ] = 2;
				q.push((P){nextI, nextJ});
			}
		}
	}
	
	int res=0;
	for(k=0; k<zero.size(); k++) {
		i = zero[k].i;
		j = zero[k].j;
		if(!cp[i][j]) {
			q.push(zero[k]);
			cp[i][j] = 1;
			res++;
		}
	}
	while(!q.empty()) {
		int curI = q.front().i;
		int curJ = q.front().j;
		q.pop();
		
		for(k=0; k<4; k++) {
			int nextI = curI+di[k];
			int nextJ = curJ+dj[k];
			if(safe(nextI, nextJ) && !cp[nextI][nextJ]) {
				cp[nextI][nextJ] = 1;
				q.push((P){nextI, nextJ});
				res++;
			}
		}
	}
	return res;
}

int main()
{
	int i, j, k;
	scanf("%d%d", &n, &m);
	
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%d", &g[i][j]);
			cp[i][j] = g[i][j];
			if(g[i][j] == 2) virus.push_back((P){i, j});
			else if(!g[i][j]) zero.push_back((P){i, j});
		}
	}

	int ans=0;
	int zSize = zero.size();
	for(i=0; i<zSize-2; i++) {
		g[zero[i].i][zero[i].j] = 1;
		for(j=i+1; j<zSize-1; j++) {
			g[zero[j].i][zero[j].j] = 1;
			for(k=j+1; k<zSize; k++) {
				g[zero[k].i][zero[k].j] = 1;
				int tmp = go();
				if(ans < tmp) ans = tmp;
				g[zero[k].i][zero[k].j] = 0;
			}
			g[zero[j].i][zero[j].j] = 0;
		}
		g[zero[i].i][zero[i].j] = 0;
	}
	printf("%d\n", ans);
	return 0;
}
