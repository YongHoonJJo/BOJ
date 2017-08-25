#include <cstdio>

int cnt;
char w[31];

struct Trie {
	Trie *go[128];
	bool goExist;
	int output;

	Trie() {
		for(int i=0; i<128; i++)
			go[i] = NULL;
		goExist = 0;
		output = 0;
	}
	
	void insert(char *key) {
		if(*key == 0) {
			output++;
			cnt++;
			return ;
		}
		
		if(!go[*key]) go[*key] = new Trie();
		goExist = 1;
		go[*key]->insert(key+1);
	}
	
	void print(int idx) {
		if(output) {
			w[idx] = 0;
			printf("%s %.4lf\n", w, output*100.0/cnt);
			if(!goExist) return ;
		}
		
		for(int i=0; i<128; i++) {
			if(go[i]) {
				w[idx] = i;
				go[i]->print(idx+1);
			}
		}
	}

};

int main()
{
	Trie *root = new Trie();
	while(gets(w)) root->insert(w);
	root->print(0);
	return 0;
}
