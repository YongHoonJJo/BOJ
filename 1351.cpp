#include <cstdio>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> a;
int p, q;

long long go(long long n)
{
	if(a[n]) return a[n];

	return a[n] = go(n/p) + go(n/q);
}

int main()
{
	long long n;
	scanf("%lld %d %d", &n, &p, &q);

	a[0] = 1;
	printf("%lld\n", go(n));
}
