void main()
{
  int a, b;
	float c, d;

	printf("두 숫자 입력 : ");
	scanf("%d %d", & a, & b);

	c = a / b;
	d = (float)a / b;

	printf("두 수의 비율 : %f %f", c, d);
}
