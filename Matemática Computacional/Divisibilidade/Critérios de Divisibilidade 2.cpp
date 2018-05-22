#include <stdio.h>

main() {
	
	char n;
	int l1;
	int l2;
	int s = 0;
	
	while(true) {
		scanf("%c", &n);
		if(n != 10) {
			n -= 48;
			l1 = l2;
			l2 = n;
			s += n;			
		}
		else {
			break;
		}
	}
	
	if(!((l1*10+l2)%4) ||
		l1%2&&(l2==2||l2==6) ||
		!(l1%2)&&(!l2||!(l2%4))) {
		printf("S");
	}
	else {
		printf("N");
	}
	
	printf(s%9 ? "\nN\n" : "\nS\n");
	
	printf((l1*10+l2)%25 ? "N" : "S");
	
}
