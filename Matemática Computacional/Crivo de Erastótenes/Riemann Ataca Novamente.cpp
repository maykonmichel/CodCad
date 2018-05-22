#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1300010;

int mrk[MAX];

main() {
	
	int Q;
	int n;
	int k = 3;
	vector<int> p;
	p.push_back(2);
	mrk[4] = true;
	
	scanf("%d", &Q);
	
	for(int q=0; q<Q; q++) {
		scanf("%d", &n);
		
		for(int c=1; p.back()!=n; c++, k++) {
			//printf("k = %d\n", k);
			if(!mrk[k]) {
				p.push_back(k);
				for(int i=2; i<c; i++) {
					if(i*k >= MAX) {
						break;
					}
					mrk[i*k] = true;
				}
			}
			for(int i=0; i<p.size(); i++) {
				if(c*p[i] >= MAX) {
					break;
				}
				mrk[c*p[i]] = true;
			}
		}
		
		printf("%d\n", p.size());
	}
	
}
