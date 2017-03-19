#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;

	while(scanf("%d", &n)>0) {
		int i, k, Lidx=0;
		vector<int> lis;

		for(i=0; i<n; i++) {
			scanf("%d", &k);
			if(!i) {
				lis.push_back(k);
			}
			else {
				if(lis[Lidx] < k) {
					lis.push_back(k);
					Lidx++;
				}
				else {
					int pos = lower_bound(lis.begin(), lis.end(), k)-lis.begin();
					lis[pos] = k;
				}
			}
		}
		printf("%d\n", Lidx+1);
	}

	return 0;
}

