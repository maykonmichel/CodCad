#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int ENTER = 10;
const int MAX = 300010;

int lis(vector<int> &v) {
	vector<int> t;	//Topo das "pilhas"
	for(int k=0; k<v.size(); k++) {
		vector<int>::iterator it = upper_bound(t.begin(), t.end(), v[k]);
		if(it == t.end()) {
			t.push_back(v[k]);
		}
		else {
			*it = v[k];
		}
	}
	return t.size();
}

main() {
	
	int c;
	vector<int> v;
	
	while(true) {
		scanf("%c", &c);
		if(c != ENTER) {
			v.push_back(c);
		}
		else {
			break;
		}
	}
	
	printf("%d", lis(v));
	
}
