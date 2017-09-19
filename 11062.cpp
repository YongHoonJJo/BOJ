#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int card[1001];
int d[1001][1001][2];

//앨리스일때는 항상 앨리스의 점수가 최선이 되는 선택을 하고,
//로봇의 턴일 때는 항상 앨리스의 점수가 최하가 되는 선택을 한다.
//(전체 카드의 점수 - 앨리스의 점수 = 로봇의 점수이므로)
//앨리스의 점수를 최저로 하는 선택이 로봇에게 있어서 최적의 선택이 된다.
int go(int s, int e, bool turn)
{
	int &ret = d[s][e][turn];
	if(ret != -1) return ret;
	if(s == e) return turn ? card[s] : 0;

	return ret = turn ? max(go(s+1, e, 0)+card[s], go(s, e-1, 0)+card[e]) :
		min(go(s+1, e, 1), go(s, e-1, 1));
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int i, n;
		scanf("%d", &n);

		for(i=0; i<n; i++)
			scanf("%d", card+i);
		memset(d, -1, sizeof(d));
		printf("%d\n", go(0, n-1, 1));
	}
}
