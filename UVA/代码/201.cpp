//============================================================================
// Name        : UVA.cpp
// Author      : WSL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<stdio.h>
#include<string.h>
int main() {
	int n;
	int time = 0;
	while (scanf("%d", &n) == 1) {
		int count[n];
		int H[n][n - 1];
		int V[n - 1][n];
		memset(H, 0, sizeof(H));
		memset(V, 0, sizeof(V));
		memset(count, 0, sizeof(count));
		int m;
		scanf("%d", &m);
		getchar();
		for (int i = 0; i < m; i++) {
			char cc;
			int r, c;
			scanf("%c%d%d", &cc, &r, &c);
			getchar();
			if (cc == 'H') {
				H[r - 1][c - 1] = 1;
			} else if (cc == 'V') {
				V[c - 1][r - 1] = 1;
			}
		}
		for (int r = 0; r < n - 1; r++) {
			for (int c = 0; c < n - 1; c++) {
				for (int x = 0; x < n - 1 - r; x++) {
					if (H[r + x][c] == 1 && H[r + x + 1][c] == 1 && V[r][c + x] == 1
							&& V[r][c + 1 + x] == 1) {
						count[x]++;
					} else
						break;
				}
			}
		}
		if(time++)
            printf("\n**********************************\n\n");
		printf("Problem #%d\n\n", time);
		bool isnull = true;
		for(int i = 0; i < n ; i++){
            if(count[i]){
                isnull = false;
                printf("%d square (s) of size %d\n", count[i], i + 1);
            }
		}
		if(isnull)
            printf("No completed squares can be found.\n");
	}
	return 0;
}
