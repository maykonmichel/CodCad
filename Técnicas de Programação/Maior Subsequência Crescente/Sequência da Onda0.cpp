#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int lis(vector<int> &v) {
	vector<int> t;
	multiset<int> ms;
	for(int k=0; k<v.size(); k++) {
		vector<int>::iterator it = lower_bound(t.begin(), t.end(), v[k]);
		if(it == t.end()) {
			t.push_back(v[k]);
		}
		ms.insert(v[k]);
	}
	int r1 = 1;
	int r2 = 1;
	for(int k=0; k<t.size(); k++) {
		if(ms.count(t[k]) > 1) {
			r2 += 2;
		}
		else {
			r2 = max(r1, r2);
			r1 = 1;
		}
	}
	return r2;
}

main() {
	
	int m;
	int a;
	vector<int> v;
	
	scanf("%d", &m);
	
	for(int k=0; k<m; k++) {
		scanf("%d", &a);
		v.push_back(a);
	}
	
	printf("%d", lis(v));
	
}
