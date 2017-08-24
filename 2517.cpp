#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct P { int x, i; };

vector<P> v;
int seg[1<<20];
int sIdx=(1<<20)/2;

bool cmp(P a, P b)
{
	return a.x > b.x;	
}

void update(int i, int val)
{
	i += sIdx;
	seg[i] = val;
	while(i > 1) {
		i >>= 1;
		seg[i] = seg[i*2]+seg[i*2+1];
	}
}

int Run(int L, int R, int node, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return seg[node];
	return Run(L, R, node*2, nodeL, mid)+Run(L, R, node*2+1, mid+1, nodeR);
}

int main()
{
	int n, x;
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		scanf("%d", &x);
		v.push_back((P){x, i});
	}

	sort(v.begin(), v.end(), cmp);	

	vector<int> ans(n);
	for(int i=0; i<n; i++) {
		int idx = v[i].i;
		int Sum = Run(0, idx, 1, 0, sIdx-1);
		ans[idx] = Sum+1;
		update(idx, 1);
	}

	for(int i=0; i<n; i++)
		printf("%d\n", ans[i]);
}
