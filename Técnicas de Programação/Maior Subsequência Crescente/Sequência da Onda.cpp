#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100010;

void show(vector<int> v) {
	printf("\n\n");
	for(int k=0; k<v.size(); k++) {
		printf("%d ", v[k]);
	}
	printf("\n\n\n");
}

vector<int> lis(vector<int> v) {
	vector<int> p;
	for(int k=0; k<v.size(); k++) {
		vector<int>::iterator it = lower_bound(p.begin(), p.end(), v[k]);
		if(it == p.end()) {
			p.push_back(v[k]);
		}
		else {
			*it = v[k];
		}
	}
	//show(p);
	return p;
}

main() {
	
	int m;
	int n;
	vector<int> a;
	
	scanf("%d", &m);
	
	for(int k=0; k<m; k++) {
		scanf("%d", &n);
		a.push_back(n);
	}
	
	vector<int> b = lis(a);
	
	reverse(a.begin(), a.end());
	
	a = lis(a);
	
	int r = 0;
	for(int k=0; k<a.size(); k++) {
		vector<int>::iterator it = find(b.begin(), b.end(), a[k]);
		if(it != b.end()) {
			r = max(r, min(k+1, (int)(it-b.begin())));
		}
	}
	
	printf("%d", 2*r+1);
	
}
