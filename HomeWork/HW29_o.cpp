/*
	!!������

	���� ����(10 ~ 9999)�� �Է� �޾�, �� �ڸ����� �����Ͽ� ���� ���մϴ�.
	�� ���� ���� ���������� �� �ڸ����� �����ؼ� ���� �����ô�.
	�̷��� ������ ����� ������ 1�� �ڸ����� �����ϰ� �Ǵµ� �̷��� ���� ������ �ݺ� Ƚ���� �������� �Ѵ�.

	@2017.01.06 pm06:22
*/

//inputUInt ���ľ���
#if 0
#include <stdio.h>

int inputUInt(char*);
int transNumber(int);
void myflush();

int main()
{
	int inputStart, inputLast, inputTerms, num, result;
	int countTerms , countLast = 0, memory;

	inputStart = inputUInt("���� ��(P1) : ");
	inputLast = inputUInt("�� ��(P2) : ");
	inputTerms = inputUInt("������(N) : ");

	while (inputStart <= inputLast)
	{
		memory = inputStart;
		countTerms = 0;

		while ((memory / 10) != 0)
		{
			memory = transNumber(memory);
			countTerms++;
		}
		if (countTerms == inputTerms)
		{
			printf("%d\n", inputStart);
			countLast++;
		}

		inputStart++;
	}
	printf("�� ���� : %d", countLast);
/*
	while (inputStart <= inputLast)
	{
		countTerms = 1;
		printf("1\n");
		while (1)
		{
			printf("2\n");
			if ((inputStart / 10) != 0)
			{
				 memory = transNumber(memory);
				 countTerms++;
			}
			else
				break;
		}
		
		if (countTerms == inputTerms)
		{
			printf("%d\n", &inputStart);
			countLast++;
		}
		inputStart++;
	}
	printf("�� ���� : %d", countLast);
	*/
}

int transNumber(int num)
{
	int thou, hund, ten, one, memory, result;

	if (num >= 1000)
	{
		thou = num / 1000;
		memory = num - (thou * 1000);
		
		hund = memory / 100;
		memory -= hund * 100;
		
		ten = memory / 10;
		memory -= ten * 10;

		one = memory;

		result = thou * hund * ten * one;
	}
	else if (num >= 100)
	{
		hund = num / 100;
		memory = num - (hund * 100);

		ten = memory / 10;
		memory -= ten * 10;

		one = memory;

		result = hund * ten * one;
	}
	else
	{
		ten = num / 10;
		memory = num - (ten * 10);

		one = memory;

		result = ten * one;
	}

	return result;
}

// ���� �Է½� ���� ����   (���� ����)
int inputUInt(char *message)
{
	int num;

	while (1)
	{
		printf("%s", message);
		scanf("%d", &num);

		if (num > 0)
				break;

		myflush();
	}

	return num;
	
/*
	while (1)
	{
		printf("# ���� ������ �Է� �Ͻÿ�(100 ~ 9999) : ");
		ret = scanf("%d", &input);

		if (ret == 1)
		{
			if ((input >= 100) && (input <= 9999))
				break;
			else
				printf("���� ������ ���Ѽ� �ٽ� �Է� �Ͻÿ�.\n");
		}
		else
		{
			printf("������ �Է� �ϼ���~ ^^\n");
			getchar();
		}
	}
*/
}

void myflush()
{
	while (getchar() != '\n')
		;
}
#endif