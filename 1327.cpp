#include <stdio.h>

char check[87654322];
int q[2322432], f, r;
int n, k;

int go(int n)
{
	switch(n) {
		case 2: return 12;
		case 3: return 123;
		case 4: return 1234;
		case 5: return 12345;
		case 6: return 123456;
		case 7: return 1234567;
	}
	return 12345678;
}

int sToN(char str[], int s)
{
	int i, ret=0;
	int e = s+k-1;
	char tmp[10]={0};

	for(i=0; i<n; i++)
		tmp[i] = str[i];
	
	for(i=0; i<k/2; i++) {
		char tCh = tmp[s];
		tmp[s++] = tmp[e];
		tmp[e--] = tCh;
	}

	for(i=0; i<n; i++) {
		ret *= 10;
		ret += (tmp[i]-'0');
	}
	return ret;
}

int main()
{
	int i;
	int ans, state=0, ok=0, cnt=-1;
	scanf("%d %d", &n, &k);

	ans = go(n);

	for(i=0; i<n; i++) {
		int x;
		scanf("%d", &x);
		state*=10;
		state+=x;
	}
	q[r++] = state;
	check[state] = 1;

	while(!ok && f != r) {
		int rr = r;
		cnt++;
		
		while(f != rr) {
			int cur = q[f++];
			char nStr[9]={0};
			int idx = n;

			if(cur == ans) {
				ok = 1;
				break;
			}

			while(cur) {
				nStr[--idx] = (cur%10)+'0';
				cur/=10;
			}
			
			for(i=0; i<=n-k; i++) {
				cur = sToN(nStr, i);
				if(!check[cur]) {
					check[cur] = 1;
					q[r++] = cur;
				}
			}
		}
	}

	if(!ok) cnt = -1;
	printf("%d\n", cnt);

	return 0;
}
