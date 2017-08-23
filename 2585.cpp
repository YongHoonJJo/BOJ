#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

struct P { int x, y; };
struct P2 { int x, y, cnt; };
vector<P> v;

bool isOk(int ans, int k)
{
	queue<P2> q;
	bool visited[1001]={0};

	q.push((P2){0, 0, 0});
	while(!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		if(cnt <= k) {
			int x = 10000 - curX;
			int y = 10000 - curY;
			double dist = sqrt((x*x)+(y*y));
			if(dist <= ans) 
				return 1;

			for(int i=0; i<v.size(); i++) {
				if(!visited[i]) {
					x = v[i].x - curX;
					y = v[i].y - curY;
					dist = sqrt((x*x)+(y*y));
					if(dist <= ans) {
						q.push((P2){v[i].x, v[i].y, cnt+1});
						visited[i] = 1;
					}
				}
			}
		}
	}		
	return 0;
}

int main()
{
	int i, n, k;
	scanf("%d%d", &n, &k);

	for(i=0; i<n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back((P){x, y});
	}

	int s = 0;
	int e = 14142;
	while(s <= e) {
		int mid = (s+e)/2;
		if(isOk(mid, k)) e = mid-1;
		else s = mid+1;
	}
	if(s%10 == 0) s /= 10;
	else s = (s+10)/10;
	printf("%d\n", s);
	return 0;
}
