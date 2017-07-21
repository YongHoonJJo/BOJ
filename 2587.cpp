#include <stdio.h>

int main()
{
	int i, sum=0;
	int idx=0, cnt=2;	
	int a[5], check[10]={0};

	for(i=0; i<5; i++) {
		scanf("%d", a+i);
		sum += a[i];
		check[a[i]/10]++;
	}

	while(cnt) {
		if(check[idx] == 0)
			idx++;
		else {
			check[idx]--;
			cnt--;
		}
	}

	printf("%d\n", sum/5);
	for(i=1; i<10; i++) {
		if(check[i]) {
			printf("%d\n", i*10);
			break;
		}
	}
	return 0;
}
