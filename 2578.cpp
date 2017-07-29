#include <stdio.h>

int main()
{
	int i, j, k, ans=0;
	int bingo[5][5], call[25];
	
	for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			scanf("%d", &bingo[i][j]);
	for(k=0; k<25; k++) 
		scanf("%d\n", &call[k]);

	for(k=0; k<25; k++) {
		for(i=0; i<5; i++) {
			for(j=0; j<5; j++) {
				if(bingo[i][j] == call[k]) {
					int x, cnt = 0;
					bingo[i][j] = 0;
					
					for(x=0; x<5; x++)
						if(bingo[i][x] == 0)
							cnt++;
					if(cnt == 5) ans++; cnt=0;
					
					for(x=0; x<5; x++)
						if(bingo[x][j] == 0)
							cnt++;
					if(cnt == 5) ans++; cnt=0;

					if(i == j) {
						for(x=0; x<5; x++)
							if(bingo[x][x] == 0)
								cnt++;
						if(cnt == 5) ans++; cnt=0;
					}

					if(i+j == 4) {
						for(x=0; x<5; x++)
							if(bingo[4-x][0+x] == 0)
								cnt++;
						if(cnt == 5) ans++; 
					}
				}
			}
		}
		if(ans >= 3) {
			printf("%d\n", k+1);
			return 0;
		}
	}
	return 0;
}
