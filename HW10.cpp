#pragma waning(disable : 4996);
#include <stdio.h>

int main()
{
	int num1, num2;
	double slu;

	printf("�ΰ��� ������ �Է��Ͻÿ� : ");
	scanf("%d %d", &num1, &num2);

	slu = (double)num1 / num2;

	printf("%d + %d = %d \n", num1, num2, num1 + num2);
	printf("%d - %d = %d \n", num1, num2, num1 - num2);
	printf("%d * %d = %d \n", num1, num2, num1 * num2);
	printf("%d / %d = %.2lf \n", num1, num2, slu);
}
