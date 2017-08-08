#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
	return a.compare(b) < 0;
}

int main()
{
	int i, j, n;
	scanf("%d", &n);

	map<string, bool> msb;

	vector<string> w[51];
	while(n--) {
		string s;
		cin >> s;
		if(msb[s] == 0) {
			w[s.size()].push_back(s);
			msb[s] = 1;
		}
	}

	for(i=1; i<51; i++) {
		if(w[i].size())
			sort(w[i].begin(), w[i].end(), cmp);
	}

	for(i=1; i<51; i++) {
		for(j=0; j<w[i].size(); j++)
			cout << w[i][j] << '\n';
	}
}
