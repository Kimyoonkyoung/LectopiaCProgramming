/*
	!!���ڿ� �޸�(,) �߰��ϱ�

	������ �Էµ� ���ڸ� ���ڷ� ��ȯ�Ͽ� ����ϴ� ���α׷� �ۼ�
	�ԷµǴ� ���� 1���� 20�� �̸��� ������ �����ϸ�, ��ȯ�� ���ڴ� ���ڸ� �������� 
	�޸�(,)�� ǥ���Ѵ�.
	�ݺ������ϸ� ���� �Է� �� ����

	@2017.01.13 pm06:31
*/
#if 0
#include <stdio.h>

int inputInt();
void myflush();
void exchangeChar(int, char*);

int main()
{
	int inputCost;
	char exChar[100];

	while (1)
	{
		inputCost = inputInt();

		if (inputCost < 0)
			break;

		exchangeChar(inputCost, exChar);

		printf(" %d -> %s\n\n", inputCost, exChar);
	}
}

void exchangeChar(int inputCost, char *exChar)  // ',' = 44
{
	int i, j = 0, k = 0, save = 0, count = 0, exInt[100] = { 0 , };

	for (i = 1000000000; i >= 1; i /= 10)
	{
		if ((inputCost / i) >= 1)
		{
			save = inputCost / i;
			inputCost = inputCost - (save * i);
			exInt[j] = (save + 48);
			j++;

			if ((i == 1000000000) || (i == 1000000) || (i == 1000))
			{
				exInt[j] = 44;
				j++;
			}
			count++;
		}
		else if(count > 0)
		{
			exInt[j] = 48;
			j++;
		} 
	}

	while (exInt[k] != 0)
	{
		exChar[k] = exInt[k];

		k++;
	}
	exChar[k] = '\0';
}

int inputInt()
{
	int input;

	printf("# �ݾ� �Է� : ");

	while(1)
	{
		scanf("%d", &input);

		if (getchar() == '\n')
			break;

		myflush();

		printf("# �ݾ� �Է� : ");
	}

	return input;
}

void myflush()
{
	while (getchar() != '\n')
		;
}
#endif