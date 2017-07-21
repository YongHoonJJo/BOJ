#include <stdio.h>

int main()
{
	int i, p[7]={0};
	int ans;

	for(i=1; i<=6; i++)
		scanf("%d", p+i);

	ans = p[6];
	ans += p[5];
	while(p[5]) {
		p[1] -= 11;
		if(p[1] < 0) p[1] = 0;
		p[5]--;
	}

	ans += p[4];
	while(p[4]) { 
		if(p[2]>5) {
			p[2] -= 5;
		}
		else {
			p[1] -= ((5-p[2])*4);
			if(p[1] < 0) p[1] = 0;
			p[2] = 0;
		}
		p[4]--;
	}

	ans += ((p[3]+3)/4);
	p[3] %= 4;
	if(p[3]) {
		if(p[3] == 3) {
			if(p[2]) p[2]--;
			else p[1] -= 4;
			p[1] -= 5;
		}
		else if(p[3] == 2) {
			if(p[2] >= 3) {
				p[2] -= 3;
			}
			else {
				p[1] -= ((3-p[2])*4);
				p[2] = 0;
			}
			p[1] -= 6;
		}
		else if(p[3] == 1) {
			if(p[2] >= 5)
				p[2] -= 5;
			else { 
				p[1] -= ((5-p[2])*4);
				p[2] = 0;
			}
			p[1] -= 7;
		}
		if(p[1] < 0) p[1] = 0;
	}
	ans += ((p[2]+8)/9);
	p[2] %= 9;

	if(p[2]) {
		p[1] -= ((9-p[2])*4);
		if(p[1] < 0) p[1] = 0;
		p[2] = 0;
	}
	ans += ((p[1]+35)/36);
	printf("%d\n", ans);

	return 0;
}
