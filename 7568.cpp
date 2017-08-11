#include <stdio.h>

typedef struct dc {
	int x, y;
} Dc;

int main()
{
	int i, j, n;
	Dc std[51];

	scanf("%d", &n);

	for(i=0; i<n; i++) 
		scanf("%d%d", &std[i].x, &std[i].y);

	for(i=0; i<n; i++) {
		int cnt = 1;
		for(j=0; j<n; j++)
		if(std[i].x < std[j].x && std[i].y < std[j].y)
			cnt++;
		printf("%d ", cnt);
	}
		
	return 0;
}
