#include <stdio.h>

int input();

int main()
{
	int number;
	number = input();

	printf("�Էµ� ���� 8������ %#o�Դϴ�. \n", number);
	printf("�Էµ� ���� 16������ %#x�Դϴ�. \n", number);
}

int input()
{
	int ret;

	printf("�������� �Է��ϼ���. : ");
	scanf_s("%d", &ret);

	return ret;
}