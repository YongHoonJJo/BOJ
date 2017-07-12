#include <stdio.h>

int arr[10], idx;

int isP()
{
	int i;
	for(i=0; i<idx/2; i++)
		if(arr[i] != arr[idx-1-i])
			return 0;
	return 1;
}


int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, a, b=0;
		scanf("%d", &n);
		a = n;

		do {
			b *= 10;
			b += n%10;
			n /= 10;
		} while(n);

		idx = 0;
		n = a+b;
		while(n) {
			arr[idx++] = n%10;
			n /= 10;
		}
		
		if(isP()) puts("YES");
		else puts("NO");

	}

	return 0;
}
