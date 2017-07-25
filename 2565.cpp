#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct P { int a, b; };

bool cmp(P a, P b)
{
	return a.b < b.b;
}

int main()
{
	int n;
	scanf("%d", &n);

	vector<P> v;
	for(int i=0; i<n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back((P){a, b});
	}
	
	sort(v.begin(), v.end(), cmp);

	vector<int> tmp(1,v[0].a), lis(1,v[0].a);
	for(int i=1; i<n; i++) {
		int k = v[i].a;
		tmp.push_back(k);
		if(lis.back() < k) {
			lis.push_back(k);
		}
		else {
			int pos = lower_bound(lis.begin(), lis.end(), k)-lis.begin();
			lis[pos] = k;
		}
	}
	printf("%d\n", n-lis.size());
}
