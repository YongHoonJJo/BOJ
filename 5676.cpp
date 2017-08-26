#include <stdio.h>

int seg[1<<18];
int sIdx=1<<17;

void update(int i, int val)
{
	i += sIdx;
	seg[i] = val;
	
	while(i > 1) {
		i >>= 1;
		seg[i] = seg[i*2]*seg[i*2+1];
	}
}

int Mul(int L, int R, int node, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 1;
	if(L <= nodeL && nodeR <= R) return seg[node];
	return Mul(L, R, node*2, nodeL, mid)*Mul(L, R, node*2+1, mid+1, nodeR);
}

int main()
{
	int n, k;
	while(scanf("%d%d", &n, &k) == 2) {
		int i, num;
		for(i=1; i<=n; i++) {
			scanf("%d", &num);
			if(!num) update(i, 0);
			else num > 0 ? update(i, 1) : update(i, -1);
		}
		while(k--) {
			char cmd;
			int a, b;
			scanf(" %c%d%d", &cmd, &a, &b);
			if(cmd == 'C') {
				if(b > 0) b = 1;
				else if(b < 0) b = -1;
				update(a,  b);
			}
			else {
				int ret = Mul(a, b, 1, 0, sIdx-1);
				if(!ret) printf("0");
				else printf("%c", ret > 0 ? '+' : '-');
			}
		}
		puts("");
	}

	return 0;
}
