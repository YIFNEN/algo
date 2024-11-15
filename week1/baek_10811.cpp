#include<stdio.h>
int arr[100];

void change(int n, int m)
{
	while (n < m) {
		int temp = arr[n];
		arr[n] = arr[m];
		arr[m] = temp;
		++n;
		--m;
	}
}

int main(void) {
	int x, y, a, b;
	
	

	scanf_s("%d %d/n", &x, &y);


	for (int i = 0; i < x; i++) 
	{
		arr[i] = i + 1;
	}


	for (int i = 0; i < y; i++)
	{
		scanf_s("%d %d/n", &a, &b);
		change(a-1, b-1);
	}
	
	for (int i = 0; i < x; i++)
	{
		printf("%d ", arr[i]);
	}
	
	

	return 0;
}

