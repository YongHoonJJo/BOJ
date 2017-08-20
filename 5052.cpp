#include <cstdio>
#define MAX 10


struct Trie {
	Trie *go[MAX];
	bool output;
	bool goExist;

	Trie() {
		for(int i=0; i<MAX; i++)
			go[i] = NULL;
		output = goExist = false;
	}

	~Trie() {
		for(int i=0; i<MAX; i++)
			if(go[i])
				delete go[i];
	}

	void insert(const char *key) {
		if(*key == 0) {
			output = true;
			return ;
		}

		int cur = *key - '0';
		if(!go[cur]) go[cur] = new Trie();
		goExist = true;
		go[cur]->insert(key+1);
	}

	bool consistent() {
		if(output && goExist)
			return false;

		for(int i=0; i<MAX; i++)
			if(go[i] && !go[i]->consistent())
				return false;
		return true;
	}
};

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int n;
		scanf("%d", &n);

		Trie *root = new Trie();
		while(n--) {
			char Tel[11];
			scanf("%s", Tel);
			root->insert(Tel);
		}
		root->consistent() ? puts("YES") : puts("NO");	
		delete root;
	}
}
