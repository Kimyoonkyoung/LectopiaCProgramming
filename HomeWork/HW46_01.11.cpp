/*
	!!¦,Ȧ ���ϱ�

	Ű����κ��� ���� ���� �� ���� �Է� �ް�, Ȧ���� ���� ������ ¦���� ���� ��������
	�Է� �޾� �� �� ���̿� �����ϴ� Ȧ���� ¦���� ����ϰ� �� ���� ���Ͽ� ����Ͻÿ�.
	��, �̶� �� ���� ���� �� ���� �۰ų� ���� ��쿡�� �ٽ� �Է� ������, 
	¦Ȧ�� ���� �� e �� o �����̿��� ���� �Է� �� ���Է��� �䱸

	@2017.01.11 pm09:40	
*/
#if 0
#include <stdio.h>

void inputNumber(int*, int*);
char inputSelect(int*, int*);
void output(int*, int*, char);

int main()
{
	int numStart, numLast;
	char inputSelec;

	inputNumber(&numStart, &numLast);
	inputSelec = inputSelect(&numStart, &numLast);
	output(&numStart, &numLast, inputSelec);
}

void inputNumber(int *numStart, int *numLast)
{
	while (1)
	{
		printf("# ���� ���� �Է��Ͻÿ� : ");
		scanf("%d", numStart);

		if (*numStart > 0 && getchar() == '\n')
			break;
	}
	while (1)
	{
		printf("# �� ���� �Է��Ͻÿ� : ");
		scanf("%d", numLast);

		if (*numLast > *numStart && getchar() == '\n')
			break;

		getchar();
	}
}

char inputSelect(int *numStart, int *numLast)
{
	char select;

	while (1)
	{
		printf("* %d~%d������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ", *numStart, *numLast);
		scanf("%c", &select);

		if (select == 'e' || select == 'o')
			break;

		getchar();
	}

	return select;
}

void output(int *numStart, int *numLast, char select)
{
	int i, sum = 0;

	switch (select)
	{
	case 'e':
		if ((*numStart % 2) == 0)
		{
			printf("  %d~%d������ ¦��(", *numStart, *numLast);
			for (i = *numStart; i <= *numLast; i += 2)
			{
				printf("%d ", i);
				sum += i;
			}
			printf("\b)�� ���� %d �Դϴ�.", sum);
		}
		else
		{
			printf("  %d~%d������ ¦��(", *numStart, *numLast);
			for (i = (*numStart + 1); i <= *numLast; i += 2)
			{
				printf("%d ", i);
				sum += i;
			}
			printf("\b)�� ���� %d �Դϴ�.", sum);
		}
		break;
	case 'o':
		if ((*numStart % 2) == 0)
		{
			printf("  %d~%d������ Ȧ��(", *numStart, *numLast);
			for (i = (*numStart + 1); i <= *numLast; i += 2)
			{
				printf("%d ", i);
				sum += i;
			}
			printf("\b)�� ���� %d �Դϴ�.", sum);
		}
		else
		{
			printf("  %d~%d������ Ȧ��(", *numStart, *numLast);
			for (i = *numStart; i <= *numLast; i += 2)
			{
				printf("%d ", i);
				sum += i;
			}
			printf("\b)�� ���� %d �Դϴ�.", sum);
		}
		break;
	}
}
#endif