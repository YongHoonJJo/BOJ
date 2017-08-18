#include <cstdio>
#include <vector>
using namespace std;

vector<int> L[501], H[501];
int ansL[501], ansH[501]; 
int visitedL[501], visitedH[501]; 

int dfsL(int cur, int k)
{
	int ret=0;
	visitedL[cur] = k;

	for(int i=0; i<L[cur].size(); i++) {
		int next = L[cur][i];
		if(visitedL[next] != k)
			ret += dfsL(next, k)+1;
	}
	return ret;
}

int dfsH(int cur, int k)
{
	int ret=0;
	visitedH[cur] = k;

	for(int i=0; i<H[cur].size(); i++) {
		int next = H[cur][i];
		if(visitedH[next] != k)
			ret += dfsH(next, k)+1;
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
		L[a].push_back(b);
		H[b].push_back(a);
	}

	for(int i=1; i<=n; i++) {
		ansL[i] = dfsL(i, i);	
		ansH[i] = dfsH(i, i);
	}	

	int ans=0;
	for(int i=1; i<=n; i++) {
		if(ansL[i]+ansH[i]+1 == n)
			ans++;
	}
	printf("%d\n", ans);
}
