#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 1000000000

int n, p, w[16][16], d[16][1<<16];
char YN[17];

int pStation(int status, int cnt)
{
	int &ret = d[cnt][status];

	if(cnt >= p) return 0;
	if(ret != -1) return ret;

	ret = INF;
	for(int i=0; i<n; i++) {
		if(status&(1<<i)) {
			for(int j=0; j<n; j++) {
				if(!(status&(1<<j)))
					ret = min(ret, pStation(status|(1<<j), cnt+1)+w[i][j]);
			}
		}
	}
	return ret;
}

int main()
{
	int i, j, status=0, cnt=0;
	scanf("%d", &n);

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &w[i][j]);

	scanf("%s%d", YN, &p);

	for(i=0; i<n; i++) {
		if(YN[i] == 'Y') {
			cnt++;
			status |= (1<<i);
		}
	}

	memset(d, -1, sizeof(d));

	int ans = pStation(status, cnt);

	if(ans == INF) ans = -1;
	printf("%d\n", ans);
}
