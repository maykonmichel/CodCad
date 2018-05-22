//CodCad - Estrutura de dados - Union-Find - Guildas

#include <stdio.h>

const int MAX = 100010;

int g[MAX];	//Guildas
int h[MAX]; //Altura das guildas
int p[MAX];	//Pontuação das guildas

int find(int x) {
	if(g[x] == x) {
		return x;
	}
	return g[x]=find(g[x]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	
	if(a == b) {
		return;
	}
	if(h[a] > h[b]) {
		g[b] = a;
		p[a] += p[b];
	}
	else if(h[a] < h[b]) {
		g[a] = b;
		p[b] += p[a];
	}
	else {
		g[b] = a;
		p[a] += p[b];
		h[a]++;
	}
}

main() {
	
	int n;	//Número de jogadores
	int m;	//Número de ações
	
	while(scanf("%d %d", &n, &m) && n) {
		for(int k=1; k<=n; k++) {
			scanf("%d", &p[k]);
			g[k] = k;
			h[k] = 1;
		}
		
		int q;	//Tipo de ação
		int a;	//Guilda A
		int b;	//Guilda B
		
		int v = 0;	//Vitórias de Rafael
		
		while(m--) {
			scanf("%d %d %d", &q, &a, &b);
			if(q == 1) {
				join(a, b);
			}
			else {
				a = find(a);
				b = find(b);
				int r = find(1);
				if(r==a && p[a]>p[b] || r==b && p[b]>p[a]) {
					v++;
				}
			}
		}
		
		printf("%d\n", v);
	}
	
}
