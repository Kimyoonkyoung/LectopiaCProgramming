#include <stdio.h>

int inputKw();
void outputCharge(double outCha);

int main()
{
	double chargeAll, use, chargeLast;
	double duty;
	double chargeBasic = 660;
	double chargeKw = 88.5;

	use = inputKw();

	chargeAll = chargeBasic + (use * chargeKw);

	duty = chargeAll * (9.0/ 100.0);

	chargeLast = chargeAll + duty;

	outputCharge(chargeLast);
}

int inputKw()
{
	int kw;
	printf("���� ��뷮�� �Է��ϼ���(kw) : ");
	scanf_s("%d", &kw);

	return kw;
}

void outputCharge(double outCha)
{
	printf("���� ������� %lf�� �Դϴ�.", outCha);
}