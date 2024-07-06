#include <stdio.h>

void main()
{
  int score = 0;
	printf("몇까지 할지 숫자를 입력해주세요 : ");
	scanf("%d", &score);
	int num;
	int count = 0;
	for (int i = 1; i <= score; i++) 
	{
		num = i;
		while (1) 
		{
			if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9) 
			{
				printf("짝 \n");
				count++;
			}
			else
			{
				printf("%d \n", num);
			}
			num /= 10;
			if (num == 0) 
			{
				break;
			}
		}
	}
	 총 박수 횟수 출력하기
	printf("1~40까지의 총 박수 : %d", count);
}
