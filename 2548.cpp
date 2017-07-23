#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, a[20001];
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++)
		scanf("%d", a+i); 	

	sort(a+1, a+1+n);
	
	int pSum[20001]={0};
	for(int i=1; i<=n; i++)
		pSum[i] = pSum[i-1]+a[i];

	int ans=0, Min=pSum[n];
	for(int i=1; i<=n; i++) {
		int tmp = (a[i]*i) - pSum[i];
		tmp += (pSum[n]-pSum[i]-(a[i]*(n-i)));
		if(Min > tmp) {
			Min = tmp;
			ans = a[i];
		}
	}
	printf("%d\n", ans);	
	return 0;
}
