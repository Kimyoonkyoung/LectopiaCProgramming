#include <stdio.h>

int inputAgg();

int main()
{
	int aggHeight, boxAdd = 0;

	while (1)
	{
		aggHeight = inputAgg();

		if (aggHeight > 500)
			printf("* Ÿ���� ������ �峭���� ���ÿ�~ ^^\n");
		else if (aggHeight < 150)
			printf("* ���߸��� ������ �峭���� ���ÿ�~ ^^\n");
		else
		{
			boxAdd++;
			printf("* ���� �ް��� �� : %d \n", boxAdd);
			if (boxAdd == 10)
				break;
		}
	}
	printf("\n*** �ް� ������ �������ϴ�.\n");
}

int inputAgg()
{
	int ret, input;

	while (1)
	{
		printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
		ret = scanf("%d", &input);

		if (ret == 1)
			break;
		else
		{
			printf("������ �Է� �ϼ���~ ^^\n");
			getchar();
		}
	}

	return input;
}