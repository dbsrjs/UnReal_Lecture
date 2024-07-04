void main()
{
	int n;

	printf("숫자를 입력하세요 : ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int num = i;
		int has369 = 0;

		while (num > 0)
		{
			  int digit = num % 10;
			  if (digit == 3 || digit == 6 || digit == 9)
			  {
  				has369 = 1;
				  break;
			  }
			  num /= 10;
    }
    if (has369)
    { 
      printf("짝 \n");
    }
    else
    {
      printf("%d \n", i);
    }
	}
}
