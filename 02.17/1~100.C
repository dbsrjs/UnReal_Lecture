void main()
{
  int i = 1, sum = 0;

	while (i <= 100)
	{
		sum += i;
		++i;
	}

	for (int i = 1; i <= 100; i++)
		sum += i;
  
	printf("1부터 100까지의 합 : %d \n", sum);
}
