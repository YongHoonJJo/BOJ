#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX	100001

vector<int> v[MAX];
int parent[MAX][18], depth[MAX]; 

int main()
{
	int i, j, n, k;
	int a, b;
	scanf("%d", &n);

	for(i=1; i<n; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	depth[1] = 1;

	q.push(1);
	while(!q.empty()) {
		int sz=q.size();

		for(i=0; i<sz; i++) {
			int cur = q.front();
			q.pop();

			for(j=0; j<v[cur].size(); j++) {
				int next = v[cur][j];
				if(!depth[next]) {
					depth[next] = depth[cur]+1;
					parent[next][0] = cur;
					q.push(next);
				}
			}
		}
	}
	for(j=0; j<17; j++)
		for(i=1; i<=n; i++)
			if(parent[i][j])
				parent[i][j+1] = parent[parent[i][j]][j];

	scanf("%d", &k);
	while(k--) {
		scanf("%d %d", &a, &b);
		
		if(depth[a] < depth[b]) swap(a, b);	
		int diff = depth[a] - depth[b];

		for(j=0; diff; j++) {
			if(diff%2) a = parent[a][j];
			diff/=2;
		}
		
		if(a != b) {
			for(j=17; j>=0; j--) {
				if(parent[a][j] && parent[a][j] != parent[b][j]) {
					a = parent[a][j];
					b = parent[b][j];
				}
			}
			a = parent[a][0];
		}
		printf("%d\n", a);
	}

	
}
