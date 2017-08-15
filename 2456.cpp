#include <cstdio>
#include <algorithm>
using namespace std;

struct P { int i, sum, cnt[4]; }; 

P ans[4];

bool cmp(P a, P b)
{
	if(a.sum == b.sum) {
		if(a.cnt[3] == b.cnt[3]) 
			return a.cnt[2] > b.cnt[2];
		return a.cnt[3] > b.cnt[3];
	}
	return a.sum > b.sum;
}

int main()
{
	int n;
	scanf("%d", &n);

	for(int i=1; i<4; i++) 
		ans[i].i = i;

	while(n--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		ans[1].sum += a; ans[1].cnt[a]++;
		ans[2].sum += b; ans[2].cnt[b]++;
		ans[3].sum += c; ans[3].cnt[c]++;
	}

	sort(ans+1, ans+4, cmp);

	int ansI, ansS = ans[1].sum;
	if(ans[1].sum == ans[2].sum) {
		if(ans[1].cnt[3] == ans[2].cnt[3]) {
			if(ans[1].cnt[2] == ans[2].cnt[2]) ansI = 0;
			else ansI = ans[1].i;
		}
		else 
			ansI = ans[1].i;
	}
	else
		ansI = ans[1].i;
	printf("%d %d\n", ansI, ansS);
		
}
