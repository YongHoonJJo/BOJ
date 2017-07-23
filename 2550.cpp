#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int i, n;
	int sw[10001], b[10001];
	int sm[10001], line[10001];
	int mm[10001];

	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", sw+i);
		sm[sw[i]-1] = i;
		mm[sm[sw[i]-1]] = sw[i];
	}
	for(i=0; i<n; i++) {
		scanf("%d", b+i);
		line[i] = sm[b[i]-1]; 
	}

	int idx=0;
	vector<int> lis, p(n+1, -1);
	lis.push_back(line[0]);

	for(i=1; i<n; i++) {
		int k = line[i];
		if(lis[idx] < k) {
			p[k] = lis[idx++];
			lis.push_back(k);
		}
		else {
			int pos = lower_bound(lis.begin(), lis.end(), k)-lis.begin();
			lis[pos] = k;
			if(pos != 0)
				p[k] = lis[pos-1];
		}
	}
	printf("%d\n", idx+1);

	int c = lis[idx];
	vector<int> ans;
	while(c != -1) {
		ans.push_back(mm[c]);
		c = p[c];
	}
	sort(ans.begin(), ans.end());
	for(i=0; i<ans.size(); i++)
		printf("%d ", ans[i]);
	puts("");
}
