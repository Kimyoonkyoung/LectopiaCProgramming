/*
	!!3�� 4�� ¥�� 2���� int �迭�� ��, ���� ���� ���ϱ�

	int 3�� 4��¥�� num�迭�� �����Ͽ� ������ ���� 1~9 ������ ������ �ʱ�ȭ �� �� 
	�� ���� ���� �� ���� �հ�, ���� �հ踦 ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	@2017.01.12 pm07:05
*/
#if 0
#include <stdio.h>
#include <stdlib.h>

int random(int);
void numReset(int(*)[4]);
void aryCalculator(int(*)[4]);

int main()
{
	int num[3][4];

	numReset(&num[0]);
	aryCalculator(&num[0]);
	
}

void aryCalculator(int (*num)[4])
{
	int i, j, sum;

	for (i = 0; i < 3; i++)
	{
		sum = 0;
		printf("%d��\t: ", i);
		for (j = 0; j < 4; j++)
		{
			printf("%4d", num[i][j]);
			sum += num[i][j];
		}
		printf("   \t%i ���� �� : %d\n", i, sum);
	}

	printf("���� �� : ");

	for (i = 0; i < 4; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum += num[j][i];
		}
		printf("%4d", sum);
	}
	printf("\n");
}

void numReset(int (*num)[4])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			//srand((unsigned int)time(NULL));
			num[i][j] = random(9) + 1;
		}
	}
}

int random(int n)
{
	int ret;
	ret = rand() % n;
	return ret;
}
#endif
