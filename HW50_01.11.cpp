/*
	!!�ּҰ�, �ִ밪 ã��(1)

	������ ���� 5���� Ű����κ��� �Է� �޾Ƽ� �迭�� �����Ѵ�.
	����� ���� �߿��� ���� ū ���� ���� ���� ã�� ����ϴ� ���α׷��� �ۼ��Ѵ�.
	�ϴ� ù ��° �迭����� ���� ���� ũ�ٰ�(�Ǵ� �۴ٰ�) ������ �Ŀ� �� ���� ������ �迭����� ����� ���ϸ� �ȴ�.

	@2017.01.12 am09:18
*/
#if 0
#include <stdio.h>

void inputArray(double*);
double minCalculator(double*);
double maxCalculator(double*);
void outputMaxMin(double, double);

int main()
{
	double mmArray[5], max, min;

	inputArray(mmArray);
	max = maxCalculator(mmArray);
	min = minCalculator(mmArray);
	outputMaxMin(max, min);
}

void outputMaxMin(double max, double min)
{
	printf("\n���� ū �� : %.2lf\n", max);
	printf("���� ���� �� : %.2lf\n", min);
}

double maxCalculator(double *mmArray)
{
	double storage;
	int i;

	storage = mmArray[0];

	for (i = 1; i < 5; i++)
	{
		if (storage < mmArray[i])
			storage = mmArray[i];
	}

	return storage;
}

double minCalculator(double *mmArray)
{
	double storage;
	int i;

	storage = mmArray[0];

	for (i = 1; i < 5; i++)
	{
		if (storage > mmArray[i])
			storage = mmArray[i];
	}

	return storage;
}

void inputArray(double *mmArray)
{
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		printf("%d �� �� �� : ", i);
		scanf("%lf", &mmArray[i]);

		if (getchar() != '\n')
		{
			i -= 1;
			continue;
		}
	}
	/*while (1)
	{	
		printf("%d �� �� �� : ", i);
		scanf("%d", &mmArray[i]);

		i++;
	}*/
}
#endif