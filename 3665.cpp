#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int i, j;
		int n, m, k;
		int rank[501]={0}, ind[501]={0};
		int check[501][501]={0};
		int cnt=0, ans[500]={0};
		bool know = 1;
		scanf("%d", &n);

		for(i=1; i<=n; i++) {
			scanf("%d", rank+i);
			ind[rank[i]]=i-1;
		}

		vector<int> v[501];
		for(i=1; i<n; i++) {
			int idx=1;
			for(j=i+1; j<=n; j++) { 
				v[rank[i]].push_back(rank[j]);
				check[rank[i]][rank[j]] = idx++;
			}
		}

		scanf("%d", &m);
		while(m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			if(check[a][b]) { int t=a; a=b; b=t; }

			v[a].push_back(b);
			v[b][check[b][a]-1]=0;
			ind[b]++;
			ind[a]--;
		}

		queue<int> q;
		for(i=1; i<=n; i++)
			if(!ind[i])
				q.push(i);

		while(!q.empty()) {
			int x = q.front();
			if(q.size() > 1) {
				puts("?");
				know = 0;
				break;
			}
			q.pop();
			ans[cnt++] = x;

			for(i=0; i<v[x].size(); i++) {
				int y = v[x][i];
				if(y) {	
					ind[y]--;
					if(!ind[y])
						q.push(y);
				}
			}
		}

		if(know) {
			if(cnt != n)
				puts("IMPOSSIBLE");
			else {
				for(i=0; i<n; i++)
					printf("%d ", ans[i]);
				puts("");
			}
		}
	}
}
