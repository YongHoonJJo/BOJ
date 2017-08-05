#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> lis(1, k);

	for(int i=1; i<n; i++) {
		scanf("%d", &k);
		if(lis.back() < k)
			lis.push_back(k);
		else {
			int pos = lower_bound(lis.begin(), lis.end(), k) - lis.begin();
			lis[pos] = k;
		}
	}
	printf("%d\n", n-lis.size());
}
