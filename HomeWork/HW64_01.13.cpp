/*
	!!�ִ밪, �ּҰ� ã��(2)

	int ary[100] �迭�� �����͸� ���ϴ� ��ŭ �����͸� �Է� �޾� �� �� �߿� �ִ밪�� �ּҰ��� ���Ͽ� ����Ͻÿ�.
	�̶� �ִ밪�� �ּҰ��� ���� �� ��°�������� �Բ� ���Ͽ� ����ϴ� ���α׷� �ۼ�
	�ݺ� �����ϰ� ���� �Է½� ���� (sort ��� ���x)

	@2017.01.13 pm06:18
*/
#if 0
#include <stdio.h>

int inputArray(int*);
int minCalculator(int*, int, int*);
int maxCalculator(int*, int, int*);
void outputMaxMin(int, int, int*, int*);

int main()
{
	int ary[100], max, min, indexMax = 0, indexMin = 0, aryLength;

	while (1)
	{
		aryLength = inputArray(ary);

		if (aryLength == -1)
			break;

		max = maxCalculator(ary, aryLength, &indexMax);
		min = minCalculator(ary, aryLength, &indexMin);

		outputMaxMin(max, min, &indexMax, &indexMin);
	}
	//max = maxCalculator(ary);
	//min = minCalculator(ary);
	//outputMaxMin(max, min);
}

void outputMaxMin(int max, int min, int *indexMax, int *indexMin)
{
	printf("\n���� ū �� : %d(index:%d) / ", max, *indexMax);
	printf("���� ���� �� : %d(index:%d)\n\n", min, *indexMin);
}

int maxCalculator(int *mmArray, int aryLength, int *indexMax)
{
	int storage;
	int i;

	storage = mmArray[0];

	for (i = 1; i < aryLength; i++)
	{
		if (storage < mmArray[i])
		{
			storage = mmArray[i];
			*indexMax = i;
		}
	}

	return storage;
}

int minCalculator(int *mmArray, int aryLength, int *indexMin)
{
	int storage;
	int i;

	storage = mmArray[0];

	for (i = 1; i < aryLength; i++)
	{
		if (storage > mmArray[i])
		{
			storage = mmArray[i];
			*indexMin = i;
		}
	}

	return storage;
}

int inputArray(int *mmArray)
{
	int i = 0, ret;

	printf("* ���� �Է� : ");

	while (1)
	{
		ret = scanf("%d", &mmArray[i]);

		if (ret == 0)
			return -1;

		if (mmArray[i] == 0)
			break;

		i++;
	}

	return i;
	/*while (1)
	{
	printf("%d �� �� �� : ", i);
	scanf("%d", &mmArray[i]);

	i++;
	}*/
}
#endif