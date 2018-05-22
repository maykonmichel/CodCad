#include <stdio.h>

int mdc(int a, int b) {
	if(!b) {
		return a;
	}
	return mdc(b, a%b);
}

main() {
	
	int n;
	
	scanf("%d", &n);
	
	int a;
	int b;
	
	scanf("%d", &a);
	
	for(int k=1; k<n; k++) {
		scanf("%d", &b);
		a = mdc(a, b);
	}
	
	printf("%d", a);
	
}
