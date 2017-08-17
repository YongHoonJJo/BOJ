#include <cstdio>
#include <vector>
using namespace std;

vector<int> H[101], L[101];
vector<bool> visitedH, visitedL;
int ansH[101], ansL[101];

int dfsH(int cur)
{
	int ret = 0;
	visitedH[cur] = 1;
	
	for(int i=0; i<H[cur].size(); i++) {
		int next = H[cur][i];
		if(!visitedH[next]) 
			ret += dfsH(next)+1;
	}
	return ret;
}

int dfsL(int cur)
{
	int ret = 0;
	visitedL[cur] = 1;
	
	for(int i=0; i<L[cur].size(); i++) {
		int next = L[cur][i];
		if(!visitedL[next]) 
			ret += dfsL(next)+1;
	}
	return ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		H[a].push_back(b);
		L[b].push_back(a);
	}

	for(int i=1; i<=n; i++) {
		visitedH = vector<bool>(n+1); ansH[i] = dfsH(i);
		visitedL = vector<bool>(n+1); ansL[i] = dfsL(i);
	}

	for(int i=1; i<=n; i++) 
		printf("%d\n", n-ansL[i]-ansH[i]-1);

}
