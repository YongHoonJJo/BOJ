#include <stdio.h>

int NUM[101];
int ans[101];

int main(){
	int i, N ;
	int count=0, from= 0, value;

	scanf("%d", &N);
	for(i=0; i<N; i++){
		int k;
		scanf("%d", &k);
		NUM[i]= k;
	}
	printf("%d\n", N) ;

	value = NUM[count];
	while( count < N ) {
		while( ans[from] != 0 ) { 
			from = (from+1)%N; 
		}
		ans[from] = value;
		from = (value + from) % N; 
		value = NUM[++count]; 
	}
	for(i=0; i<101; i++)
		if(ans[i])
			printf("%d ", ans[i]);
	puts("");
	return(0);
}
