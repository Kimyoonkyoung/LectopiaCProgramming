/*
	!!���� �Լ� �����

	���� ���� n���ϴ� �Լ��� �Ǽ� ���� n���ϴ� �Լ��� �ۼ��Ͻÿ�.(��ȯ ���� n���� ���)
	��, 0�� � �µ� 0�̰�, � ���� 0���� �׻� 1�̸�, ���� ��������� �����ϸ�, ����¸� ���ϴ� ������ ���� ��.

	@2017.01.07 pm08:03
*/

#if 0
#include <stdio.h>

int inputUInt(char*);
double inputDouble(char*);
int ipow(int, int);
double fpow(double, int);

int main()
{
	int N, numI;
	double numD, nD;

	numI = inputUInt("* ���� ���� ���� �Է� �Ͻÿ� : ");
	printf("* ���� ���� �Է� �Ͻÿ� : ");
	scanf("%d", &N);
	printf("%d�� %d���� %d�Դϴ�. \n\n",numI, N,ipow(numI, N));

	numD = inputDouble("* ���� �Ǽ� ���� �Է� �Ͻÿ� : ");
	printf("* ���� ���� �Է� �Ͻÿ� : ");
	scanf("%d", &N);
	printf("%.2lf�� %d���� %.3lf �Դϴ�.",numD, N, fpow(numD, N));
}

int inputUInt(char *msg)
{
	int ret;

	printf("%s", msg);
	scanf("%d", &ret);

	return ret;
}

double inputDouble(char *msg)
{
	double ret;

	printf("%s", msg);
	scanf("%lf", &ret);

	return ret;
}

int ipow(int num, int N)
{
	int i, result = 1;

	if (N != 0)
	{
		for (i = 0; i < N; i++)
			result *= num;

		return result;
	}

	return 0;
}

double fpow(double num, int N)
{
	int i;
	double result = 1.0;

	if (N != 0)
	{
		for (i = 0; i < N; i++)
			result *= num;

		return result;
	}

	return 0.0;
}
#endif