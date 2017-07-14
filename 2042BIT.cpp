#include <cstdio>
#include <vector>
using namespace std;

typedef long long lli;

lli sum(vector<lli> &tree, int i)
{
	lli ans=0LL;
	while(i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(vector<lli> &tree, int i, lli diff)
{
	while(i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<lli> a(n+1);
	vector<lli> tree(n+1);
	for(int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
		update(tree, i, a[i]);
	}
	m += k;
	while(m--) {
		int t1;
		scanf("%d", &t1);
		if(t1 == 1) {
			int t2;
			lli t3;
			scanf("%d%lld", &t2, &t3);
			lli diff = t3-a[t2];
			a[t2] = t3;
			update(tree, t2, diff);
		}
		else {
			int t2, t3;
			scanf("%d%d", &t2, &t3);
			printf("%lld\n", sum(tree, t3)-sum(tree,t2-1));
		}
	}
}
