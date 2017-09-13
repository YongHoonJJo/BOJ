#include <cstdio>
#include <vector>
using namespace std;

struct P { int x, y; };

inline int abs(int x) { return x > 0 ? x : -x; }

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int n;
		vector<P> v;
		scanf("%d", &n);
		
		for(int i=0; i<n+2; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			v.push_back((P){x, y});
		}

		int g[105][105]={0};
		for(int i=0; i<v.size(); i++) {
			int curX = v[i].x;
			int curY = v[i].y;
			for(int j=0; j<v.size(); j++) {
				int nX = v[j].x;
				int nY = v[j].y;
				if(abs(curX-nX)+abs(curY-nY) <= 1000)
					g[i][j] = 1;
			}
		}

		for(int k=0; k<n+2; k++)
			for(int i=0; i<n+2; i++)
				for(int j=0; j<n+2; j++)
					if(g[i][k] && g[k][j])
						g[i][j] = 1;

		g[0][n+1] ? puts("happy") : puts("sad");	
	}
}
