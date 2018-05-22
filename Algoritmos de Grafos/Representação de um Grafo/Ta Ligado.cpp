#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

main() {
	
	int n;	//Ilhas
	int m;	//Interações
	int t;	//Tipo de interação => 0(Ponte?)/1(Ponte)
	int a;	//Cidade A
	int b;	//Cidade B
	
	scanf("%d %d", &n, &m);
	
	vector<int> p[n+1];	//Pontes
	
	for(int k=0; k<m; k++) {
		scanf("%d %d %d", &t, &a, &b);
		if(t) {
			p[a].push_back(b);
			p[b].push_back(a);
		}
		else {
			printf("%d\n", find(p[a].begin(), p[a].end(), b) != p[a].end() ? 1 : 0);
		}
	}
	
}
