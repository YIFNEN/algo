#include<stdio.h>

int main(void) {
	int n, dx, dy, xarea;
	int sum = 0;
	scanf_s("%d", &n);
	int arr[100][100] = { {0,} };
			
	for(int i=0; i < n; i++) {
			scanf_s("%d %d", &dx, &dy);
			for (int x = dx; x < dx + 10; x++) {
				for (int y = dy; y < dy + 10; y++) {
					arr[x][y] = 1;
				}
			}	
	}

	for (int j = 0; j < 100; j++) {
		for (int k = 0; k < 100; k++) {
			if (arr[j][k] == 1)
				sum = sum + 1;
		}
	}

	printf("%d", sum);
	return 0;
}