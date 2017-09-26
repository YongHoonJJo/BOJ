#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, Max=0;
	scanf("%d", &n);

	vector<int> v, t;
	for(int i=0; i<n; i++) {
		int k;
		scanf("%d", &k);
		v.push_back(k);
		t.push_back(k);
	}

	sort(t.begin(), t.end());	

	for(int i=0; i<n; i++) {
		t[i] += n-i;
		if(Max < t[i]) Max = t[i];
	}

	int ans = 0; 
	for(int i=0; i<n; i++) {
		if(Max <= v[i]+n)
			ans++;
	}
	printf("%d\n", ans);
}
