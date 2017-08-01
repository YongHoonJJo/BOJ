#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct P { int i, k; };

bool cmp(P a, P b)
{
	return a.k < b.k;
}

int main()
{
	int n, k;
	scanf("%d", &n);

	vector<P> v;
	for(int i=1; i<=n; i++) {
		scanf("%d", &k);
		v.push_back((P){i, k});
	}

	sort(v.begin(), v.end(), cmp);
	
	vector<int> lis(1, v[0].i);
	for(int i=1; i<n; i++) {
		k = v[i].i;
		if(lis.back() < k)
			lis.push_back(k);
		else {
			int pos = lower_bound(lis.begin(), lis.end(), k) - lis.begin();
			lis[pos] = k;
		}
	}
	printf("%d\n", lis.size());
}
