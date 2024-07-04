void main()
{
  while (1)
	{
		int menu[5] = {1000, 1000, 1200, 1300, 1500};
		char name[5][20] = { {"콜라"}, {"사이다"},{"환타"},{"커피"},{"우유"} };

		int money;	//넣은 돈
		int n;	//음료 번호

		printf("\n");
		printf("\n");

		printf("자판기 메뉴 \n");
		for (int i = 0; i < sizeof(menu) / sizeof(int); i++)
			printf("%d. %s(%d원) \n", i + 1, name[i], menu[i]);
		printf("6. 자판기 종료 \n");

		
		printf("원하는 음료의 번호를 입력 해주세요 : ");
		scanf("%d", &n);

		if (n - 1 > sizeof(menu)/sizeof(int))
		{
			printf("존재하지 않는 상품입니다. 다시 입력해주세요. \n");
			continue;
		}
		if (n == 6)
		{
			printf("자판기를 종료합니다 \n");
			break;
		}

		printf("돈을 넣어주세요 : ");
		printf("\n");
		scanf("%d", &money);

		if (money >= menu[n-1])
		{
			printf("%s를 제공합니다 \n", &name[n-1]);
			printf("잔돈은 %d원입니다. \n", money - menu[n - 1]);
		}
		else
		{
			printf("돈이 부족합니다 다시 입력해주세요 \n");
		}
	}
}
