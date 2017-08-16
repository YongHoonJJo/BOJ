#include <stdio.h>
#define MAX 200000
#define MOD	1000000007
typedef long long lli;

lli segSum[1<<19];
int segCnt[1<<19];
int sIdx=(1<<19)/2;

void update(int i, int v)
{
	i += sIdx;
	segCnt[i]++;
	segSum[i] += v;

	while(i != 1) {
		i >>= 1;	
		segSum[i] = segSum[i*2]+segSum[i*2+1];
		segCnt[i] = segCnt[i*2]+segCnt[i*2+1];
	}
}

lli sum(int L, int R, int nodeN, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return segSum[nodeN];
	return sum(L, R, nodeN*2, nodeL, mid)+sum(L, R, nodeN*2+1, mid+1, nodeR);
}

int cnt(int L, int R, int nodeN, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return segCnt[nodeN];
	return cnt(L, R, nodeN*2, nodeL, mid)+cnt(L, R, nodeN*2+1, mid+1, nodeR);
}

int main()
{
	int i, n, k, ans=1;
	scanf("%d %d", &n, &k);

	update(k, k);		
	for(i=1; i<n; i++) {
		lli L, R;
		scanf("%d", &k);
		L = 1LL*k*cnt(0, k, 1, 0, sIdx-1) - sum(0, k, 1, 0, sIdx-1);
		R = sum(k+1, MAX, 1, 0, sIdx-1) - 1LL*k*cnt(k+1, MAX, 1, 0, sIdx-1);
		ans  = (L+R) % MOD * ans % MOD;
		update(k, k);		
	}
	printf("%d\n", ans);
	return 0;
}
