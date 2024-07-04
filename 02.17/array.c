void main()
{
  int arr[10] = { 2, 10, 30, 21, 34, 23, 53, 21, 9, 1 };
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 1)
		{
			printf("배열 %d 번째 원소는 짝수이다. : %d \n", i + 1, arr[i]);
		}
	}
}
