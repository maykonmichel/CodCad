#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

main() {
	
	int n;	//Encomendas
	vector<pair<int, int> > v;
	
	scanf("%d", &n);
	
	for(int k=0; k<n; k++) {
		int t;	//Tempo para confeccionar
		int d;	//Momento de entrega
		scanf("%d %d", &t, &d);
		v.push_back(make_pair(d, t));
	}
	
	sort(v.begin(), v.end());
	
	int t = 0;	//Tempo
	int a = 0;	//Atraso
	for(int k=0; k<v.size(); k++) {
		t += v[k].second;
		a = max(a, t-v[k].first);
	}
	
	printf("%d", a);
	
}
