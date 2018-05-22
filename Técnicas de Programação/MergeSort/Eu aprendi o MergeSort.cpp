#include <stdio.h>
#include <vector>

using namespace std;

const int NINF = -999999999;

void merge_sort(vector<int> &v) {
	/*printf("I: ");
	for(int k=0; k<v.size(); k++) {
		printf("%d ", v[k]);
	}
	printf("\n");*/
	if(v.size() == 1) {
		return;
	}
	vector<int> u1;
	vector<int> u2;
	for(int k=0; k<v.size()/2; k++) {
		u1.push_back(v[k]);
	}
	for(int k=v.size()/2; k<v.size(); k++) {
		u2.push_back(v[k]);
	}
	merge_sort(u1);
	merge_sort(u2);
	u1.push_back(NINF);
	u2.push_back(NINF);
	int i1 = 0;
	int i2 = 0;
	for(int k=0; k<v.size(); k++) {
		v[k] = u2[i2]>u1[i1] ? u2[i2++] : u1[i1++];
	}
	/*printf("O: ");
	for(int k=0; k<v.size(); k++) {
		printf("%d ", v[k]);
	}
	printf("\n");*/
}

main() {
	
	int n;
	vector<int> v;
	
	scanf("%d", &n);
	
	for(int k=0; k<n; k++) {
		int m;
		scanf("%d", &m);
		v.push_back(m);
	}
	
	merge_sort(v);
	
	for(int k=0; k<v.size(); k++) {
		printf("%d ", v[k]);
	}
	
}
