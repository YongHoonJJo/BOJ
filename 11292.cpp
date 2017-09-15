#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	while(1) {
		int n;
		scanf("%d", &n);
		if(!n) break;

		double maxTall=0;
		vector<string> v;
		vector<double> t;
		for(int i=0; i<n; i++) {
			string name;
			double tall;
			cin >> name >> tall;	
			v.push_back(name);
			t.push_back(tall);
			if(maxTall < tall) maxTall = tall;
		}
		for(int i=0; i<n; i++)
			if(t[i] == maxTall)
				cout << v[i] << '\n';
	}
}

