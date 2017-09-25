#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, arr[100001];
int s, e, sum, ans;

int main()
{
	int i;
	scanf("%d %d", &n, &k);

	for(i=0; i<n; i++)
		scanf("%d", arr+i);

	sum = arr[0];
	ans = n+1;

	while(s <= e && e < n) {
		if(sum >= k) {
			ans = min(ans, e-s+1);	
			if(sum == k) sum += arr[++e];
			else sum -= arr[s++];
		}
		else sum += arr[++e];
	}
	if(ans > n) ans=0;
	printf("%d\n", ans); 
}
