#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct P { int x, y; };

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int n, maxX=0;
		scanf("%d", &n);

		int x, y;
		vector<int> Y[100001]; // Y[x] : (x, Y[x])
		for(int i=0; i<n; i++) {
			scanf("%d%d", &x, &y);
			Y[x].push_back(y);
			if(maxX < x) maxX = x;
		}
		
		for(int i=0; i<=maxX; i++)
			if(Y[i].size())
				sort(Y[i].begin(), Y[i].end());

		y = 0;
		vector<P> ans;
		for(int x=0; x<=maxX; x++) {
			int sz = Y[x].size();
			if(sz == 0) continue;
			if(Y[x][0] == y) {
				for(int k=0; k<sz; k++) 
					ans.push_back((P){x, Y[x][k]});
				y = Y[x][sz-1];
			}
			else {
				for(int k=sz-1; k>=0; k--) 
					ans.push_back((P){x, Y[x][k]});
				y = Y[x][0];
			}
		}

		int m;
		scanf("%d", &m);
		while(m--) {
			int k;
			scanf("%d", &k);
			printf("%d %d\n", ans[k-1].x, ans[k-1].y);
		}		
	}
}
