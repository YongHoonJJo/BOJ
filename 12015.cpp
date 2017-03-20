#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct P { int x, i; };

int segMax[1<<21];
int sIdx=1;

void update(int i, int val)
{
	i+=sIdx;
	segMax[i] = val;
	
	while(i != 1) {
		i >>= 1;
		segMax[i] = segMax[i*2]>segMax[i*2+1] ? segMax[i*2] : segMax[i*2+1];
	}
}

int Max(int L, int R, int nodeN, int nodeL, int nodeR)
{
	int a, b, mid=(nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return segMax[nodeN];
	a = Max(L, R, nodeN*2, nodeL, mid);
	b = Max(L, R, nodeN*2+1, mid+1, nodeR);
	return a > b ? a : b;
}

bool cmp(P a, P b)
{
	if(a.x == b.x) 
		return a.i > b.i;
	else
		return a.x < b.x;
}

int main()
{
	int i, n, k;
	int s, e;
	scanf("%d", &n);

	while(sIdx < n)
		sIdx <<= 1;
	
	vector<P> v;
	for(i=0; i<n; i++) {
		scanf("%d", &k);
		v.push_back((P){k, i} );
	}

	sort(v.begin(), v.end(), cmp);
	
	for(i=0; i<n; i++) {
		int x = v[i].x;
		int idx = v[i].i;
		int big = Max(0, idx, 1, 0, sIdx-1);
		update(idx, big+1);
	}
	printf("%d\n", segMax[1]);
	return 0;
}

