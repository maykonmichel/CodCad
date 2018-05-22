#include <stdio.h>
#include <vector>

using namespace std;

int bos(vector<int> v) {
	if(v.size() == 1) {
		return v[0];
	}
	vector<int> u1;
	for(int k=0; k<v.size()/2; k++) {
		u1.push_back(v[k]);
	}
	vector<int> u2;
	for(int k=v.size()/2; k<v.size(); k++) {
		u2.push_back(v[k]);
	}
	return bos(u1)|bos(u2);
}

main() {
	
	int n;	
	int a;
	vector<int> v;
	
	scanf("%d", &n);
	
	for(int k=0; k<n; k++) {
		scanf("%d", &a);
		v.push_back(a);
	}
	
	printf("%d", bos(v));
	
}
