#include <cstdio>
#include <map>
using namespace std;

int main()
{
	int n, m, k;
	map<int, bool> mp;
	scanf("%d", &n);

	while(n--) {
		scanf("%d", &k);
		mp[k] = 1;
	}
	
	scanf("%d", &m);
	while(m--) {
		scanf("%d", &k);
		printf("%d\n", mp[k]);
	}
}
