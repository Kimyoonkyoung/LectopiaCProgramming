/*
	!!�迭 ���� �����͸� �������� �����ϱ�

	�迭�� ������ ���ڸ� �ʱ�ȭ�� �Ŀ� �� ���ڵ��� ��ġ�� �ݴ�� �ٲٴ� ���α׷��� �ۼ��Ѵ�.
	�迭�� �ϳ��� ����ϸ� �迭�� ũ�Ⱑ �ٲ���� �ڵ带 ������ �ʿ䰡 ������ �ۼ��Ѵ�.
	�� ������ ���� �ٲٱ� ���ؼ��� swap()�Լ��� �����Ͽ� �ٲٵ��� ����.

	@2017.01.12 am09:55
*/
#if 0
#include <stdio.h>

void swap(int*, int);

int main()
{
	int swapArray[5], i, arySize;

	arySize = sizeof(swapArray) / sizeof(swapArray[0]);

	printf("ó�� �迭�� ����� �� : ");
	for (i = 0; i < arySize; i++)
		scanf("%d", &swapArray[i]);

	swap(swapArray, arySize);

	printf("�ٲ� �迭�� ����� �� : ");
	for (i = 0; i < arySize; i++)
		printf("%d ", swapArray[i]);
}

void swap(int *swapArray, int arraySize)
{
	int swaping, i;

	for (i = 0; i < (arraySize / 2); i++)
	{
		swaping = swapArray[i];
		swapArray[i] = swapArray[(arraySize - 1) - i];
		swapArray[(arraySize - 1) - i] = swaping;
	}
}
#endif