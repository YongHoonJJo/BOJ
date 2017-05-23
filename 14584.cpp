#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i;
	char str[101];
	char w[20][21];
	int n, len, wLen[20];

	int sGap[101], wGap[20][21];
	int gap, nIdx, wIdx, sIdx=-1;

	scanf("%s", str);
	len = strlen(str);

	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%s", w[i]);
		wLen[i] = strlen(w[i]);
	}
	
	for(i=0; i<len-1; i++) {
		sGap[i] = str[i+1]-str[i];
		if(str[i+1] < str[i])
			sGap[i] += 26;
	}

	for(i=0; i<n; i++) {
		int k;
		for(k=0; k<wLen[i]-1; k++) {
			wGap[i][k] = w[i][k+1]-w[i][k];
			if(w[i][k+1] < w[i][k])
				wGap[i][k] += 26;
		}
	}	

	for(i=0; i<n; i++) {
		int k, idx=0;
		for(k=0; k<len-1; k++) {
			if(wGap[i][idx] == sGap[k])	{
				idx++;
				if(idx == wLen[i]-1) {
					nIdx = i;					
					sIdx = k;
					wIdx = idx-1;
					break;
				}
			}
			else {
				idx=0;
			}
		}
		if(sIdx != -1)
			break;
	}

	gap = str[sIdx]-w[nIdx][wIdx];
	if(str[sIdx] < w[nIdx][wIdx])
		gap += 26;
	
	for(i=0; i<len; i++) {
		if(str[i]-gap >= 'a')
			printf("%c", str[i]-gap);
		else
			printf("%c", str[i]-gap+26);
	}
	puts("");

	return 0;
}
