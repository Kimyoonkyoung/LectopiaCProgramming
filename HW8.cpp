#pragma waning(disable : 4996);
#include <stdio.h>

int main()
{
	int num1, num2, num3, sum;
	double ave;

	printf("����, ����, ���� ������ �Է��ϼ��� : ");
	scanf("%d %d %d", &num1, &num2, &num3);

	sum = num1 + num2 + num3;
	ave = sum / 3.0;

	printf("������ %d�̰� ����� %.2lf�Դϴ�.", sum, ave);
}
