/*
	!!2 ���� ��ȯ ���α׷�

	10������ �Է� �޾� 2������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	Bit���� ������ �� �ݺ����� ����ϸ� ������ 2�� ���� ���·� ��� ��

	@2017.01.06 pm07:10
*/

#if 0
#include <stdio.h>

int main()
{
	unsigned int inputBinary, calculator, i, result;

	printf("* 10���� ������ �Է��Ͻÿ� : ");
	scanf("%u", &inputBinary);

	calculator = 0x80000000;

	printf("%u(10) = ", inputBinary);

	for (i = 0; i <= 31; i++)
	{ 
		result = (inputBinary & calculator) >> (31-i);

		if (result == 1)
			printf("1");
		else
			printf("0");

		calculator = calculator >> 1;
	}
	printf("(2)\n");
}
#endif