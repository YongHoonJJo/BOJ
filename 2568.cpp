#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct P { int a, b; };

bool cmp(P a, P b)
{
	return a.b < b.b;
}

vector<P> v;
map<int, bool> m;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> ans;
	for(int i=0; i<n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		ans.push_back(a);
		v.push_back((P){a, b});
	}

	sort(ans.begin(), ans.end());
	sort(v.begin(), v.end(), cmp);

	vector<int> lisV(1, v[0].a), lisI(1, 0);
	vector<int> p(n, -1);
	for(int i=1; i<n; i++) {
		int k = v[i].a;	
		if(v[lisI.back()].a < k) {
			p[i] = lisI.back();
			lisI.push_back(i);
			lisV.push_back(k);
		}
		else {
			int pos = lower_bound(lisV.begin(), lisV.end(), k)-lisV.begin();
			lisI[pos] = i;
			lisV[pos] = k;
			if(pos != 0) {
				p[i] = lisI[pos-1];
			}
		}
	}
	printf("%d\n", n-lisI.size());
	
	int k = lisI.back();
	while(k != -1) {
		m[v[k].a] = 1;
		k = p[k];
	}

	for(int i=0; i<ans.size(); i++)
		if(m[ans[i]]!=1)
			printf("%d\n", ans[i]);
}
