#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct P { 
	int c, s, i; 
	bool operator< (const P &a) const {
		return s < a.s;
	}
};

//bool cmp(P a, P b) { return a.s < b.s; }

int main()
{
	int n;
	scanf("%d", &n);

	vector<P> v;
	vector<vector<int> > sz(2001);
	for(int i=0; i<n; i++) {
		int c, s;
		scanf("%d%d", &c, &s);
		v.push_back((P){c, s, i});
	}

	//sort(v.begin(), v.end(), cmp);
	sort(v.begin(), v.end());

	int pSum = 0;
	vector<int> ans(n), cSum(n+1, 0);
	for(int i=0, j=0; i<n; i++) {
		while(v[j].s < v[i].s) {
			pSum += v[j].s;
			cSum[v[j].c] += v[j].s;
			j++;
		}
		ans[v[i].i] = pSum - cSum[v[i].c];
	}

	for(int i=0; i<n; i++)
		printf("%d\n", ans[i]);

	return 0;
}
