#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random(int);
int inputNum();
int outputResult(int);

int main()
{
	int num, result = 0, count = 0;

	{
		srand((unsigned int)time(NULL));
		num = random(100) + 1;
	}

	result = outputResult(num);

	printf("���~ �¾Ҵ�~~~ ��ī��ī~~ %d ��° ���� ���߼̽��ϴ�.", result);
}

int outputResult(int random)
{
	int input, count = 0, max = 100, min = 0;

	while (1)
	{
		input = inputNum();

		count++;

		if (input == random)
			return count;
		else if (input < random)
		{
			min = input;
		}
		else if (input > random)
		{	
			max = input;
		}
		printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, max);
	}
	
	return count;
}

int inputNum()
{
	int num, ret;

	while (1)
	{
		printf("# ���ڸ� �Է��Ͻÿ� : ");
		ret = scanf("%d", &num);

		if (ret == 1)
		{
			if (num >= 1 && num <= 100)
				break;
			else
				printf("1 - 100 ������ ���ڸ� �Է� �Ͻÿ� : \n");
		}
		else
		{
			printf("1 - 100 ������ ���ڸ� �Է� �Ͻÿ� : \n");
			getchar();
		}
	}

	return num;
}

int random(int n)
{
	int ret;
	ret = rand() % n;
	return ret;
}