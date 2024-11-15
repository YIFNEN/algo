
#include<stdio.h>

int main(void) {
	int a, b, c;

	scanf_s("%d %d", &a, &b);

	for (int i = 0; i < a; i++) {
		scanf_s("%d", &c);
		if (c < b) {
			printf("%d ", c);
		}
	}




	return 0;
}