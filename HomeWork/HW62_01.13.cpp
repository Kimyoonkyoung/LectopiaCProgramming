/*
	!!4*4 ũ���� �࿭�� �� ����ϱ�

	4*4 ũ���� A��İ� B����� ���� ����Ͽ� C�迭�� ������ �� A,B,C �迭�� ������ ����ϴ�
	���α׷��� �ۼ��Ͻÿ�
	A, B�迭�� ������ �̸� �ʱ�ȭ �س��� ���α׷��� �ۼ�����.

	@2017.01.15 pm03:47
*/
#if 0
#include <stdio.h>

void aryCalculator(int (*)[4], int(*)[4], int(*)[4]);
void aryOutput(int(*)[4], int(*)[4], int(*)[4]);

int main()
{
	int aryA[4][4] = { {0, 1, 2, 3}, {1, -2, 1, 2}, {2, 5, -3, 2}, {0, -3, 1, 4} };
	int aryB[4][4] = { {1, -1, 2, 0},{1, -1, 1, 2}, {-1, 0, 3, 1}, {2, -1, 2, 8} };
	int aryC[4][4] = { 0 , };

	aryCalculator(aryA, aryB, aryC);

	aryOutput(aryA, aryB, aryC);
}

void aryCalculator(int (*aryA)[4], int (*aryB)[4], int (*aryC)[4])
{
	int i, j, k, sum = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				sum = aryA[i][k] * aryB[k][j];
				aryC[i][j] += sum; ;
			}
		}
	}
}

void aryOutput(int(*aryA)[4], int(*aryB)[4], int(*aryC)[4])
{
	int i, j, count;

	printf(" [Martix A]\t [Matrix B]\t [C = A * B]\n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%2d ", aryA[i][j]);
		}
		printf("\t");

		for (j = 0; j < 4; j++)
		{
			printf("%2d ", aryB[i][j]);
		}
		printf("\t");

		for (j = 0; j < 4; j++)
		{
			printf("%2d ", aryC[i][j]);
		}
		printf("\n");
	}
}
#endif