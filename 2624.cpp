#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct P { int c, n; };

vector<P> v;
int d[101][10001];

bool cmp(P a, P b)
{
	return a.c < b.c;
}

int go(int n, int T)
{
	int i, ret=0;
	if(T == 0) return 1;
	if(n < 0 || T < 0) return 0;
	if(d[n][T] != -1) return d[n][T];

	for(i=v[n].n; i>=0; i--) {
		ret += go(n-1, T-v[n].c*i);
	}
	return d[n][T]=ret;
}

int main()
{
	int i, T, k;
	scanf("%d%d", &T, &k);

	for(i=0; i<k; i++) {
		int c, n;
		scanf("%d%d", &c, &n);
		v.push_back((P){c, n});
	}

	memset(d,-1, sizeof(d));
	sort(v.begin(), v.end(), cmp);

	printf("%d\n", go(k-1, T));

	return 0;
}
