#include <stdio.h>

void main()
{
  int n;
	printf("게임의 숫자 범위를 입력하세요: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) 
	{
		int count = 0;
		int num = i;

		while (num > 0) 
		{
			int digit = num % 10;
			if (digit == 3 || digit == 6 || digit == 9)
			{
				count++;
			}
			num /= 10;
		}

		if (count > 0)
		{
			for (int j = 0; j < count; j++) 
			{
				printf("짝");
			}
		}
		else 
		{
			printf("%d", i);
		}
		printf("\n");
	}
}
