#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, cnt;
bool g[101][101];
int di[]={0, 1, 0, -1}, dj[]={-1, 0, 1,0};

bool safe(int i, int j)
{
	return (0 < i && i <=m) && (0 < j && j <=n);
}

void dfs(int i, int j)
{
	cnt++;
	g[i][j] = 1;

	for(int k=0; k<4; k++) {
		int ni = i+di[k];
		int nj = j+dj[k];
		if(safe(ni, nj) && !g[ni][nj])
			dfs(ni, nj);
	}

}

int main()
{
	scanf("%d%d%d", &m, &n, &k);

	while(k--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for(int y=b+1; y<=d; y++)
			for(int x=a+1; x<=c; x++)
				g[y][x] = 1;
	}

	vector<int> ans;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(!g[i][j]) {
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(int i=0; i<ans.size(); i++)
		printf("%d ", ans[i]);
	puts("");
}
