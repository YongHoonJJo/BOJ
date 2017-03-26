#include <cstdio>
#include <string>
#include <map>
using namespace std;

#define MAX 1000001

int p[MAX], ans[MAX];

int Find(int x)
{
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

int Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if(a != b) {
		p[a] = b;
		ans[b] += ans[a];	
	}
	return ans[b];
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int F, cnt=1;
		scanf("%d", &F);

		for(int i=1; i<MAX; i++) {
			p[i] = i;
			ans[i] = 1;
		}

		map<string, int> nw;
		while(F--) {
			char id1[21], id2[21];
			scanf("%s %s", id1, id2);
			
			if(!nw[id1]) nw[id1] = cnt++;
			if(!nw[id2]) nw[id2] = cnt++;

			printf("%d\n", Union(nw[id1], nw[id2]));				
		}
	}
}
