#include <stdio.h>

char w[5][16];

int main()
{
	int i, j;
	for(i=0; i<5; i++)
		scanf("%s", w[i]);

	for(j=0; j<16; j++)
		for(i=0; i<5; i++)
			if(w[i][j])
				printf("%c", w[i][j]);
	return 0;
}
