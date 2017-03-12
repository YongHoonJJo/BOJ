#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX	50001

vector<int> v[MAX];
int from[MAX], visited[MAX]; 

int main()
{
	int i, n, k;
	int a, b;
	scanf("%d", &n);

	for(i=1; i<n; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}	

	queue<int> q;
	q.push(1); visited[1]=1;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for(i=0; i<v[cur].size(); i++) {
			int next = v[cur][i];
			if(!visited[next]) {
				q.push(next);
				visited[next] = visited[cur]+1;
				from[next] = cur;
			}
		}
	}

	scanf("%d", &k);
	while(k--) {
		int big, small, diff;
		scanf("%d %d", &a, &b);
		if(visited[a]>visited[b]) { big=a; small=b; }
		else { big=b; small=a; }
		diff = visited[big]-visited[small];

		while(diff--) {
			big = from[big];
		}

		if(big != small) {
			while(1) {
				if(from[big] == from[small]) { 
					big = from[big];
					break;
				}
				big = from[big];
				small = from[small];
			}
		}
		printf("%d\n", big);
	}

	return 0;
}
