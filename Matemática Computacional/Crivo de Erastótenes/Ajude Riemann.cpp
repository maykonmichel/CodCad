#include <stdio.h>
#include <vector>

using namespace std;

const int MAX = 12000000;

bool mrk[MAX];

main() {
	
	int n;
	
	vector<int> p;
	
	scanf("%d", &n);
	
	for(int c=1, k=2; p.size()!=n; c++, k++) {
		if(!mrk[k]) {
			p.push_back(k);
			for(int x=2; x<c; x++) {
				if(x*k >= MAX) {
					break;
				}
				mrk[x*k] = true;
			}
		}
		for(int i=0; i<p.size(); i++) {
			if(c*p[i] >= MAX) {
				break;
			}
			mrk[c*p[i]] = true;
		}
	}
	
	printf("%d", p.back());
	
}
