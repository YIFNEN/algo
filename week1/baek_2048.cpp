#include<stdio.h>


int main(void) {
	int num1, num2, num3;
	int reward;
	int max;
	
	scanf_s("%d %d %d", &num1, &num2, &num3);

	if (num1 == num2 && num2 == num3)
	{
		reward = 10000 + num1 * 1000;

		printf("%d", reward);
	}
	else if ((num1 == num2) || (num2 == num3))
	{
		reward = 1000 + num2 * 100;

		printf("%d", reward);
	}
	else if (num1 == num3)
	{
		reward = 1000 + num1 * 100;

		printf("%d", reward);
	}
	else if ((num2 > num1) && (num2 > num3))
	{
		max = num2;
		reward = 100 * max;

		printf("%d", reward);
	}
	else if ((num1 > num2) && (num1 > num3))
	{
		max = num1;
		reward = 100 * max;

		printf("%d", reward);
	}
	else if ((num3 > num1) && (num3 > num2))
	{
		max = num3;
		reward = 100 * max;

		printf("%d", reward);
	}

	return 0;
}