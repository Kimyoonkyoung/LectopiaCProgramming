/*
	!! ������� ��� ���α׷�(switch~case�� ���)

	����� �ڵ�� ��뷮�� �Է� �޾� ��������� �Ի��Ͽ� �������

	@2017.01.08 am11:58
*/

#if 0
#include <stdio.h>
#include <string.h>

int inputCapital(int*);
int calculatorCapital(int, int);
void outputResult(int, int, int);
int inputInt(char*, int);

int main()
{
	int userCode, useCount, result;

	useCount = inputCapital(&userCode);
	result = calculatorCapital(userCode, useCount);
	outputResult(userCode, useCount, result);
}

void outputResult(int type, int use, int result)
{
	char output[1000];

	switch (type)
	{
	case 1:
		strcpy(output, "������");
		break;
	case 2:
		strcpy(output, "�����");
		break;
	case 3:
		strcpy(output, "������");
	}

	printf("\n\n# ����� �ڵ� : %d(%s)\n", type, output);
	printf("# ��뷮 : %d ton\n", use);
	printf("# �Ѽ������ : %d��", result);
}

int calculatorCapital(int type, int use)
{
	int result;

	switch (type)
	{
	case 1:
		use *= 50;
		result = use + (use * (0.05));
		break;
	case 2:
		use *= 45;
		result = use + (use * (0.05));
		break;
	case 3:
		use *= 30;
		result = use + (use * (0.05));
		break;
	}

	return result;
}

int inputCapital(int *userCode)
{
	int useCount;

	*userCode = inputInt("* ����� �ڵ带 �Է� �Ͻÿ�(1:������/2:�����/3:������) : ", 1);
	useCount = inputInt("* ��뷮�� �Է��Ͻÿ�(ton����) : ", 2);
	

	return useCount;
}

int inputInt(char *msg, int n)
{
	int inputValue;
	if(n == 1)
	{
		while (1)
		{
			printf("%s", msg);
			scanf("%d", &inputValue);

			if (getchar() == '\n' && (inputValue > 0 && inputValue < 4))
				break;
		}
	}
	else
		while (1)
		{
			printf("%s", msg);
			scanf("%d", &inputValue);

			if (getchar() == '\n' && inputValue > 0)
				break;
		}
	

	return inputValue;
}

void myflush()
{
	while (getchar() != '\n')
		;
}
#endif