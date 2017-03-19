#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int i, n, k, idx=0;
	vector<int> lis;

	scanf("%d", &n);

	for(i=0; i<n; i++) {
		scanf("%d", &k);

		if(!i) lis.push_back(k);
		else {
			if(lis[idx] < k) {
				lis.push_back(k);
				idx++;
			}
			else {
				int pos = lower_bound(lis.begin(), lis.end(), k)-lis.begin();
				lis[pos] = k;
			}
		}
	}
	printf("%d\n", n-(idx+1));
}
