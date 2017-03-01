#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001

int cost[MAX], d[MAX][2];  
vector<int> v[MAX], child[MAX];
bool visited[MAX];

void setChildren(int cur)
{
	visited[cur] = 1;

	for(int i=0; i<v[cur].size(); i++) {
		int next = v[cur][i];
		if(!visited[next]) {
			child[cur].push_back(next);
			setChildren(next);
		}
	}
}

int goodTown(int cur, bool isGood)
{
	int &ans = d[cur][isGood];
	if(ans) return ans;

	for(int i=0; i<child[cur].size(); i++) {
		int next = child[cur][i];
		int tmp = goodTown(next, 0);
		if(!isGood) tmp = max(tmp, goodTown(next, 1));
		ans += tmp;
	}
	if(isGood) ans += cost[cur];
	return ans;
}	

int main()
{
	int i, n;
	scanf("%d", &n);

	for(i=1; i<=n; i++)
		scanf("%d", cost+i);

	for(i=1; i<n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	setChildren(1);
	printf("%d\n", max(goodTown(1, 0), goodTown(1, 1)));
}
