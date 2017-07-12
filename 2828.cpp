#include <stdio.h>

int main()
{
	int n, m, j;
	int s, e, ans=0;
	scanf("%d%d%d", &n, &m, &j);

	s = 1;
	e = m;
	while(j--) {
		int k;
		scanf("%d", &k);

		if(!(s <= k && k <= e)) {
			if(k < s) {
				e -= (s-k);
				ans += (s-k);
				s = k;
			}
			else {
				s += (k-e);
				ans += (k-e);
				e = k;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
