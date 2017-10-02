#include <cstdio>

int r, c;
int V, O;
char g[255][255];
bool visited[255][255];

int di[]={0, 1, 0, -1};
int dj[]={1, 0, -1, 0};

bool safe(int i, int j)
{
	return (0 <= i && i < r) && (0 <= j && j < c);
}

void dfs(int curI, int curJ)
{
	visited[curI][curJ] = 1;
	if(g[curI][curJ] == 'v') V++;
	if(g[curI][curJ] == 'o') O++;

	for(int k=0; k<4; k++) {
		int nI = curI+di[k];
		int nJ = curJ+dj[k];
		if(safe(nI, nJ) && !visited[nI][nJ] && g[nI][nJ] != '#')
			dfs(nI, nJ);
	}
}

int main()
{
	scanf("%d%d", &r, &c);

	for(int i=0; i<r; i++) 
		scanf("%s", g[i]);

	int ansV=0, ansO=0;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(!visited[i][j] && g[i][j] != '#') {
				V = O = 0;
				dfs(i, j);
				if(O > V) ansO += O;
				else ansV += V;
			}
		}
	}
	printf("%d %d\n", ansO, ansV);
}

