#include <stdio.h>
#include <string.h>

int abs(int x)
{
	return x > 0 ? x : -x;
}

int main()
{
	int i, n, ans=0; 
	int sLen, tLen;
	int sCheck[26]={0};
	char s[11];
	scanf("%d%s", &n, s);

	sLen = strlen(s);
	for(i=0; s[i]; i++) {
		sCheck[s[i]-'A']++;
	}
	
	while(--n) {
		char t[11], check[26];
		scanf("%s", t);
		tLen = strlen(t);
		
		for(i=0; i<26; i++)
			check[i] = sCheck[i];
		for(i=0; t[i]; i++)
			check[t[i]-'A']--;

		if(sLen == tLen) {
			int cnt=0, plus=0;
			for(i=0; i<26; i++) {
				if(!check[i])
					cnt++;
				else if(check[i]>0)
					plus++;
			}
			if(cnt == 26 || (cnt == 24 && plus == 1))
				ans++;
		}
		else if(abs(sLen - tLen) == 1) {
			int cnt=0;
			for(i=0; i<26; i++) {
				if(!check[i])
					cnt++;
			}
			if(cnt == 25)
				ans++;
		}
		else
			;
	}
	printf("%d\n", ans);
}
