#include <stdio.h>

struct Trie {
	Trie *go[26];
	bool goExist;

	Trie() {
		for(int i=0; i<26; i++)
			go[i] = NULL;
		goExist = 0;
	}

	~Trie() {
		for(int i=0; i<26; i++)
			if(go[i]) delete go[i];
	}
	
	void insert(char *key) {
		if(*key == 0) return ;

		int idx = *key - 'a';
		if(!go[idx]) go[idx] = new Trie();
		goExist = 1;			
		go[idx]->insert(key+1);
	}

	bool matching(char *key) {
		if(!goExist && *key==0) return 1;

		int idx = *key - 'a'; 
		if(go[idx]) return go[idx]->matching(key+1);
		return 0;
	}
};

int main()
{
	int n, m;
	char str[501];
	scanf("%d%d", &n, &m);

	Trie *root = new Trie();
	while(n--) {
		scanf("%s", str);
		root->insert(str);
	}
	
	int ans=0;
	while(m--) {
		scanf("%s", str);
		if(root->matching(str)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
