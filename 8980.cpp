#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct P { int f, t, box; };

bool cmp(P a, P b)
{
	return a.t == b.t ? (a.f < b.f) : (a.t < b.t);
}

int main()
{
	int n, c, m;
	scanf("%d%d%d", &n, &c, &m);

	vector<P> v;
	while(m--) {
		int a, b, box;
		scanf("%d%d%d", &a, &b, &box);
		v.push_back((P){a, b, box});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	int add, ans=0;
	int bx[2001]={0};
	for(int i=0; i<v.size(); i++) {
		int j, Max=0;
		for(j=v[i].f; j<v[i].t; j++)
			if(bx[j] > Max) Max = bx[j];
		
		add = min(v[i].box, c-Max);
		for(j=v[i].f; j<v[i].t; j++)
			bx[j] += add;
		ans += add;
	}
	printf("%d\n", ans);
}
