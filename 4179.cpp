#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int r, c;
char g[1005][1005];
bool visited[1005][1005];

int dr[]={0, 1, 0, -1};
int dc[]={1, 0, -1, 0};

bool safe(int i, int j)
{
	return (0 <= i && i < r) && (0 <= j && j < c);
}

int main()
{
	scanf("%d%d", &r, &c);
	
	queue<int> J, F;
	for(int i=0; i<r; i++) {
		scanf("%s", g[i]);
		for(int j=0; j<c; j++) {
			if(g[i][j] == 'J') {
				J.push(i*1000+j);
				visited[i][j] = 1;
			}
			if(g[i][j] == 'F') F.push(i*1000+j);
		}
	}

	int ans=0;
	while(!J.empty()) {
		int sz = J.size(); 
		ans++;
		for(int i=0; i<sz; i++) {
			int curJR = J.front()/1000;
			int curJC = J.front()%1000; J.pop();
			if(g[curJR][curJC] != 'F') {
				if(curJR == 0 || curJR == r-1 || curJC == 0 || curJC == c-1) { 
					printf("%d\n", ans); 
					return 0; 
				}

				for(int k=0; k<4; k++) {
					int nJR = curJR+dr[k];
					int nJC = curJC+dc[k];
					if(!visited[nJR][nJC] && g[nJR][nJC] == '.') {
						J.push(nJR*1000 + nJC);
						visited[nJR][nJC] = 1;
					}
				}
			}
		}

		sz = F.size();
		for(int i=0; i<sz; i++) {
			int curFR = F.front()/1000;
			int curFC = F.front()%1000; F.pop();
			
			for(int k=0; k<4; k++) {
				int nFR = curFR+dr[k];
				int nFC = curFC+dc[k];
				if(safe(nFR, nFC) && g[nFR][nFC] != '#' && g[nFR][nFC] != 'F') {
					F.push(nFR*1000 + nFC);
					g[nFR][nFC] = 'F';
				}
			}
		}
	}
	puts("IMPOSSIBLE");
}
