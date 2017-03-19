#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;

	while(scanf("%d", &n)>0) {
		int i, k, idx=1, Lidx=0;
		vector<int> arr, lis;

		for(i=0; i<n; i++) {
			scanf("%d", &k);
			arr.push_back(k);
		}

		lis.push_back(arr[0]);

		while(idx < n) {
			if(arr[idx] > lis[Lidx]) {
				lis.push_back(arr[idx++]);
				Lidx++;
			}
			else {
				int pos = lower_bound(lis.begin(), lis.end(), arr[idx])-lis.begin();
				lis[pos] = arr[idx++];
			}
		}
		printf("%d\n", Lidx+1);
	}

	return 0;
}
