#include <stdio.h>

int inputF();
void outputC(double outCha);

int main()
{
	double valueF, valueC;
	
	valueF = inputF();

	valueC = 5.0 / 9.0 * (valueF - 32);

	outputC(valueC);
}

int inputF()
{
	int of;
	printf("ȭ�� �µ��� �Է��ϼ��� : ");
	scanf_s("%d", &of);

	return of;
}

void outputC(double outC)
{
	printf("���� �µ��� %.1lf�� �Դϴ�.", outC);
}