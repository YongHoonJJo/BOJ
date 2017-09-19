#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

inline int sqr(int x) { return x*x; }

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int n, m;
		scanf("%d%d", &n, &m);

		vector<int> get(n+1, 0), loss(n+1, 0);
		while(m--) {
			int a, b, p, q;
			scanf("%d%d%d%d", &a, &b, &p, &q);
			get[a] += p; get[b] += q;
			loss[a] += q; loss[b] += p;
		}
		
		int maxEx=0, minEx=0x3f3f3f3f;
		for(int i=1; i<=n; i++) {
			double Ex = !get[i] ? 0 : 1.0*sqr(get[i])/(sqr(get[i])+sqr(loss[i])); 
			int tmp = (int)(Ex*1000);
			maxEx = max(maxEx, tmp);
			minEx = min(minEx, tmp);
		}
		printf("%d\n%d\n", maxEx, minEx);
	}
}
