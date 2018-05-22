#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void show(vector<int> v) {
	printf("\n\n");
	for(int k=0; k<v.size(); k++) {
		printf("%d ", v[k]);
	}
	printf("\n\n\n");
}

int lsi(vector<int> s, vector<int> r) {
	for(int k=0; k<r.size(); k++) {
		vector<int>::iterator it = upper_bound(s.begin(), s.end(), r[k]);
		if(it != s.end()) {
			*it = r[k];
		}
	}
	show(s);
}

main() {
	
	int n;	//s1 size
	int m;	//s2 size
	int S;
	int R;
	
	vector<int> s;
	vector<int> r;
	
	scanf("%d %d", &n, &m);
	
	while(n--) {
		scanf("%d", &S);
		s.push_back(S);
	}
	
	while(m--)  {
		scanf("%d", &R);
		r.push_back(R);
	}
	
	lsi(s, r);
	
}
