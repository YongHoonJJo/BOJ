#include <stdio.h>
#include <stdlib.h>

int n, len, check[51];
int ans[51];

int safe(int x)
{
	return (1 <= x && x <= n);
}

void go(char *seq, int idx)
{
	int num=0; 
	if(*seq == 0) {
		int i;
		for(i=0; i<idx; i++)
			printf("%d ", ans[i]);
		puts("");
		exit(0);
	}

	num = *seq - '0';
	if(safe(num) && !check[num]) {
		check[num] = 1;
		ans[idx] = num;
		go(seq+1, idx+1);
		check[num] = 0;
	}
	if(seq[1]) {
		num = num*10 + seq[1]-'0';
		if(safe(num) && !check[num]) {
			check[num] = 1;
			ans[idx] = num;
			go(seq+2, idx+1);
			check[num] = 0;
		}
	}
}

int main()
{
	char seq[100];
	scanf("%s", seq);

	while(seq[len]) len++;
	n = (len+9)/2;
	go(seq, 0);
	
	return 0;
}
