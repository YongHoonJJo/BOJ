#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000001

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

int sns(int cur, int isEarly)
{
	int &ans = d[cur][isEarly];
	if(ans) return ans;

	for(int i=0; i<child[cur].size(); i++) {
		int next = child[cur][i];
		int tmp = sns(next, 0);
		if(!isEarly) tmp = max(tmp, sns(next, 1));
		ans += tmp;
	}
	if(isEarly) ans++;
	return ans;
}

int main()
{
	int i, n;
	scanf("%d", &n);
	
	for(i=1; i<n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	setChildren(1);
	printf("%d\n", n-max(sns(1, 0), sns(1, 1)));
}
