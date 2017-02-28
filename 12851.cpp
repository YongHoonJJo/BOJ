#include <cstdio>
#include <queue>
using namespace std;

#define MAX	100001

bool visited[MAX];
int ans, cnt, ok;

bool safe(int x) 
{
	return 0 <= x && x < MAX;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	queue<int> q;
	q.push(n);
	
	while(!q.empty()) {
		int sz=q.size();
		for(int i=0; i<sz; i++) {
			int x = q.front(); q.pop();
			visited[x] = 1;
			
			if(x == k) {
				ok = 1;
				cnt++;
			}

			if(safe(x+1) && !visited[x+1]) q.push(x+1);
			if(safe(x-1) && !visited[x-1]) q.push(x-1);
			if(safe(x*2) && !visited[x*2]) q.push(x*2);
		}
		if(ok) 
			break;
		ans++;
	}
	printf("%d\n%d\n", ans, cnt);
}
