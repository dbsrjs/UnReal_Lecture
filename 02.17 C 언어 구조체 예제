struct Books
{
	char name[30];	//책 이름
	char auth[30];	//저자 이름
	char publ[30];	//출판사 이름
	int borrowed;	//빌려 졌나요
};

int main()
{
	struct Books book_list[3];
	int i;

	char n;
	for (i = 0; i < 3; ++i)
	{
		printf("책 %d 정보입력(책 이름, 저자 이름, 출판사 이름) : ", i + 1);
		scanf("%s%s%s", &book_list[i].name, &book_list[i].auth,
			&book_list[i].publ);
		book_list[i].borrowed = 0;
	}

	for (i = 0; i < 3; ++i)
	{
		printf("=========\n");
		printf("책 %s의 이름 : %s \n", book_list[i].name, book_list[i].name);
		printf("책 %s의 저자 이름 : %s \n",book_list[i].name, book_list[i].auth);
		printf("책 %s의 출판사 이름 : %s \n", book_list[i].name, book_list[i].publ);

		printf("책이 대출이 된지에 대한 정보 : ");
		if (book_list[i].borrowed == 0)
		{
			printf("안 빌려짐 \n");
		}
		else
		{
			printf("빌려짐 \n");
		}
	}

	printf("빌리고 싶은 책의 이름을 입력 해주세요.");
	scanf("%s", &n);

	for (i = 0; i < 3; ++i)
	{
		if (n == book_list[i].name)
		{
			printf("책 %s를 대출해드리겠습니다. \n", n);
			book_list[i].borrowed = 1;
		}
		else
		{
			printf("존재하지 않는 책입니다. \n");
		}
	}
	return 0;
}

struct Vector
{
	float x;
	float y;
};

int main()
{
	printf("첫번째 벡터값을 입력하세요 : ");
	struct  Vector a;
	scanf("%f %f", &a.x, &a.y);

	printf("첫번째 벡터값 %f %f \n", a.x, a.y);

	printf("두번째 벡터값을 입력해주세요 : ");
	struct Vector b;
	scanf("%f %f", &b.x, &b.y);
	printf("두번째 벡터 값 %f %f \n", b.x, b.y);

	printf("두 벡터의 합 %f, %f", a.x + b.x, a.y + b.y);
}
