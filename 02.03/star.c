#include <stdio.h>

void main()
{
  for (int i = 0; i < 5; i++)
	{
		printf("***** \n");
	}

	printf("------------------ \n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("------------------ \n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 1; j <= 5 - i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("------------------ \n");

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			printf(" ");
		}

		for (int k = 0; k < i * 2 - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("------------------ \n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}

		for (int k = 0; k < 9 - 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (int i = 2; i <= 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			printf(" ");
		}

		for (int k = 0; k < i * 2 - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}
