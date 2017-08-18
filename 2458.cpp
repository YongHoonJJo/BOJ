#include <cstdio>
#include <vector>
using namespace std;

int ansL[501], ansH[501]; 
int visitedL[501], visitedH[501]; 

int dfs(vector<int> *v, int *visited, int cur, int &k)
{
	int ret=0;
	visited[cur] = k;

	for(int i=0; i<v[cur].size(); i++) {
		int next = v[cur][i];
		if(visited[next] != k)
			ret += dfs(v, visited, next, k)+1;
	}
	return ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	vector<int> L[501], H[501];
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		L[a].push_back(b);
		H[b].push_back(a);
	}

	for(int i=1; i<=n; i++) {
		ansL[i] = dfs(L, visitedL, i, i);	
		ansH[i] = dfs(H, visitedH, i, i);
	}	

	int ans=0;
	for(int i=1; i<=n; i++) {
		if(ansL[i]+ansH[i]+1 == n)
			ans++;
	}
	printf("%d\n", ans);
}
