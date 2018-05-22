#include <stdio.h>

main() {
	
	int n;	//Valor
	int v[6] = {100, 50, 25, 10, 5, 1};
	
	scanf("%d", &n);
	
	int s=0;
	for(int k=0; k<6; k++) {
		while(n%v[k] != n) {
			n -= v[k];
			s++;
		}
	}
	
	printf("%d", s);
	
}
