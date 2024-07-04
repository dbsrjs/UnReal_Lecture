struct Human
{
	int age;
	int height;
	int weight;
};

void main()
{
	struct Human Lee;

	Lee.age = 99;
	Lee.height = 185;
	Lee.weight = 80;

	printf("Psi 에대한정보\n");
	printf("나이 : %d \n", Lee.age);
	printf("키 : % d \n", Lee.height);
	printf("몸무게: %d \n", Lee.weight);
}
