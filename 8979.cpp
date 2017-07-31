#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct P { int n, g, s, d; };

bool cmp(P a, P b)
{
	return a.g == b.g ? (a.s == b.s ? (a.d > b.d) : (a.s > b.s)) : (a.g > b.g);
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	
	vector<P> v;
	for(int i=0; i<n; i++) {
		int no, g, s, d;
		scanf("%d%d%d%d",&no, &g, &s, &d);
		v.push_back((P){no, g, s, d});
	}

	sort(v.begin(), v.end(), cmp);

	int kG, kS, kD, ans;
	for(int i=0; i<n; i++) {
		if(v[i].n == k) {
			kG = v[i].g;
			kS = v[i].s;
			kD = v[i].d;
			ans = i;
			break;
		}
	}

	for(int i=ans-1; i>=0; i--) {
		if(v[i].g == kG && v[i].s == kS && v[i].d == kD)
			ans = i;
	}
	printf("%d\n", ans+1);
	return 0;
}
